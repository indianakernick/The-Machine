//
//  exit system.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "exit system.hpp"

#include "exit component.hpp"
#include "position component.hpp"
#include "player action component.hpp"

bool exitSystem(entt::registry &registry, const EntityGrid &grid) {
  const auto view = registry.view<Exit, Position>();
  for (const entt::entity entity : view) {
    const Pos pos = view.get<Position>(entity).pos;
    
    const entt::entity playerID = grid[pos].dynamicID;
    if (playerID == entt::null) {
      continue;
    }
    
    if (registry.has<PlayerAction>(playerID)) {
      return true;
    }
  }
  return false;
}
