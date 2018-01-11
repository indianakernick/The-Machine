//
//  power input system.cpp
//  The Machine
//
//  Created by Indi Kernick on 10/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "power input system.hpp"

#include "dir to vec.hpp"
#include "position component.hpp"
#include "power input component.hpp"
#include "power output component.hpp"

void powerInputSystem(ECS::Registry &registry, const EntityGrid &grid) {
  auto view = registry.view<Position, PowerInput>();
  for (const ECS::EntityID entity : view) {
    PowerInput &input = view.get<PowerInput>(entity);
    const Pos pos = view.get<Position>(entity).pos;
    input.states = Math::DirBits::NONE;
    
    for (const Math::Dir dir : Math::DIR_RANGE) {
      // target tile must be inside world
      const Pos targetPos = pos + ToVec::conv(dir);
      if (grid.outOfRange(targetPos)) {
        continue;
      }
      
      // target tile must have static entity
      const ECS::EntityID targetID = grid[targetPos].staticID;
      if (targetID == ECS::NULL_ENTITY) {
        continue;
      }
      
      if (registry.has<PowerOutput>(targetID)) {
        const Math::DirBits output = registry.get<PowerOutput>(targetID).states;
        input.states |= Math::bit(dir) & Math::opposite(output);
      }
    }
    
    input.states &= input.sides;
  }
}
