//
//  level manager.inl
//  The Machine
//
//  Created by Indi Kernick on 18/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include <fstream>
#include <Simpleton/Data/json.hpp>
#include <Simpleton/Utils/type list.hpp>

namespace detail {
  template <typename Comp>
  auto initImpl(Comp &comp, const json &node, bool)
  -> std::void_t<decltype(Comp::init(comp, node))> {
    Comp::init(comp, node);
  }
    
  template <typename Comp>
  auto initImpl(Comp &, const json &, int) {}
  
  template <typename Comp>
  void init(Comp &comp, const json &node) {
    initImpl(comp, node, true);
  }

  template <typename CompList>
  void loadEntity(ECS::Registry &registry, const json &node, const ECS::EntityID entity) {
    const json::object_t &obj = node.get_ref<const json::object_t &>();
    for (auto &pair : obj) {
      const bool gotComp = Utils::getByName<CompList>(
        pair.first,
        [&registry, &props = pair.second, entity] (auto t) {
          init(registry.assign<UTILS_TYPE(t)>(entity), props);
        }
      );
      if (!gotComp) {
        throw std::runtime_error(
          "Unknown component name \""
          + pair.first
          + "\""
        );
      }
    }
  }

  template <typename CompList>
  bool load(ECS::Registry &registry, const std::string &path) {
    std::ifstream file(path);
    if (!file.is_open()) {
      return false;
    }
    json root;
    file >> root;
    
    for (json &entityNode : root) {
      const ECS::EntityID entity = registry.create();
      loadEntity<CompList>(registry, entityNode.at("components"), entity);
    }
    
    return true;
  }
}

template <typename CompList>
bool LevelManager<CompList>::load(ECS::Registry &registry, const ECS::Level newLevel) {
  if (currentLevel != ECS::NULL_LEVEL) {
    registry.reset();
  }
  if (detail::load<CompList>(registry, levelPath(newLevel))) {
    currentLevel = newLevel;
    return true;
  } else {
    return false;
  }
}

template <typename CompList>
ECS::Level LevelManager<CompList>::current() const {
  return currentLevel;
}

template <typename CompList>
bool LevelManager<CompList>::loaded() const {
  return currentLevel != ECS::NULL_LEVEL;
}

template <typename CompList>
void LevelManager<CompList>::setPath(const std::string &newPath) {
  path = newPath;
}

template <typename CompList>
std::string LevelManager<CompList>::levelPath(const ECS::Level level) const {
  return path + std::to_string(level) + ".json";
}
