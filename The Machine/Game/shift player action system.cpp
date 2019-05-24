//
//  shift player action system.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "shift player action system.hpp"

#include "player action component.hpp"

void shiftPlayerActionSystem(entt::registry &registry) {
  auto view = registry.view<PlayerAction>();
  for (const entt::entity entity : view) {
    PlayerAction &action = view.get(entity);
    action.prev = action.curr;
  }
}
