//
//  player input response system.cpp
//  The Machine
//
//  Created by Indi Kernick on 9/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "player input response system.hpp"

#include "movement component.hpp"
#include "player action component.hpp"

namespace {
  void setActionState(entt::registry &registry, const bool enabled) {
    auto view = registry.view<PlayerAction>();
    view.each([enabled] (entt::entity, PlayerAction &comp) {
      comp.curr = enabled;
    });
  }
  
  void setDesiredDir(entt::registry &registry, const Grid::Dir dir) {
    auto view = registry.view<PlayerAction, Movement>();
    view.each([dir] (entt::entity, PlayerAction &, Movement &comp) {
      comp.desiredDir = dir;
    });
  }
  
  bool isEnabled(const KeyState state) {
    return state.downLastTick || state.down;
  }
}

void playerInputResponseSystem(entt::registry &registry, const PlayerKeyStates states) {
  setActionState(registry, isEnabled(states.action));
 
  for (const Grid::Dir dir : Grid::dir_range) {
    if (isEnabled(states.dirs[static_cast<size_t>(dir)])) {
      return setDesiredDir(registry, dir);
    }
  }
}
