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

bool exitSystem(ECS::Registry &registry, const EntityGrid &grid) {
  const auto view = registry.view<Exit, Position>();
  for (const ECS::EntityID entity : view) {
    const Pos pos = view.get<Position>(entity).pos;
    
    const ECS::EntityID playerID = grid[pos].dynamicID;
    if (playerID == entt::null) {
      continue;
    }
    
    if (registry.has<PlayerAction>(playerID)) {
      return true;
    }
  }
  return false;
}
