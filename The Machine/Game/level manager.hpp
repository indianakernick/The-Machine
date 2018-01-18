//
//  level manager.hpp
//  The Machine
//
//  Created by Indi Kernick on 18/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef level_manager_hpp
#define level_manager_hpp

#include <string>
#include <experimental/optional>
#include <Simpleton/Data/json.hpp>
#include <Simpleton/ECS/level.hpp>
#include <Simpleton/ECS/registry.hpp>

using OptionalObject = std::experimental::optional<json::object_t>;

template <typename CompList>
class LevelManager {
public:
  OptionalObject load(ECS::Registry &, ECS::Level);
  ECS::Level current() const;
  bool loaded() const;
  void setPath(const std::string &);

private:
  ECS::Level currentLevel = ECS::NULL_LEVEL;
  std::string path;
  
  std::string levelPath(ECS::Level) const;
};

#include "level manager.inl"

#endif
