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
  void setActionState(ECS::Registry &registry, const bool enabled) {
    auto view = registry.view<PlayerAction>();
    view.each([enabled] (ECS::EntityID, PlayerAction &comp) {
      comp.curr = enabled;
    });
  }
  
  void setDesiredDir(ECS::Registry &registry, const Math::Dir dir) {
    auto view = registry.view<PlayerAction, Movement>();
    view.each([dir] (ECS::EntityID, PlayerAction &, Movement &comp) {
      comp.desiredDir = dir;
    });
  }
}

void playerInputResponseSystem(ECS::Registry &registry, const PlayerKeyStates states) {
  setActionState(registry, states.action);
 
  for (const Math::Dir dir : Math::DIR_RANGE) {
    if (states.dirs[static_cast<size_t>(dir)]) {
      return setDesiredDir(registry, dir);
    }
  }
}
