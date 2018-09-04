//
//  pressure plate system.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "pressure plate system.hpp"

#include "power component.hpp"
#include "weight component.hpp"
#include "position component.hpp"
#include "pressure plate component.hpp"

void pressurePlateSystem(ECS::Registry &registry, const EntityGrid &grid) {
  auto view = registry.view<Power, Position, PressurePlate>();
  for (const ECS::EntityID entity : view) {
    Power &power = view.get<Power>(entity);
    const Pos pos = view.get<Position>(entity).pos;
    const ECS::EntityID targetID = grid[pos].dynamicID;
    
    if (targetID == entt::null) {
      power.curr = false;
      continue;
    }
    
    if (!registry.has<Weight>(targetID)) {
      power.curr = false;
      continue;
    }
    
    const bool targetHeavy = registry.get<Weight>(targetID).heavy;
    const bool plateHeavy = view.get<PressurePlate>(entity).heavy;
    
    power.curr = targetHeavy >= plateHeavy;
  }
}
