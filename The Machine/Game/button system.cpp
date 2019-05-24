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

void buttonSystem(entt::registry &registry, const EntityGrid &grid) {
  auto view = registry.view<Power, Button, Position>();
  for (const entt::entity entity : view) {
    const Pos pos = view.get<Position>(entity).pos;
    const entt::entity targetID = grid[pos].dynamicID;
    
    if (targetID == entt::null) {
      continue;
    }
    
    if (!registry.has<PlayerAction>(targetID)) {
      continue;
    }
    
    const PlayerAction action = registry.get<PlayerAction>(targetID);
    view.get<Power>(entity).curr = action.curr;
  }
}
