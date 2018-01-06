//
//  button system.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "button system.hpp"

#include "power component.hpp"
#include "button component.hpp"
#include "position component.hpp"
#include "player action component.hpp"

void buttonSystem(ECS::Registry &registry, const EntityGrid &grid) {
  auto view = registry.view<Power, Button, Position>();
  for (const ECS::EntityID entity : view) {
    const Pos pos = view.get<Position>(entity).pos;
    const ECS::EntityID targetID = grid[pos].dynamicID;
    
    if (targetID == ECS::NULL_ENTITY) {
      continue;
    }
    
    if (!registry.has<PlayerAction>(targetID)) {
      continue;
    }
    
    const PlayerAction action = registry.get<PlayerAction>(entity);
    view.get<Power>(entity).curr = action.curr;
  }
}
