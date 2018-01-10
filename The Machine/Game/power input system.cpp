//
//  power input system.cpp
//  The Machine
//
//  Created by Indi Kernick on 10/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "power input system.hpp"

#include "dir to vec.hpp"
#include "wire component.hpp"
#include "power component.hpp"
#include "position component.hpp"
#include "cross wire component.hpp"
#include "power input component.hpp"
#include "power output component.hpp"

void powerInputSystem(ECS::Registry &registry, const EntityGrid &grid) {
  auto view = registry.view<Power, Position, PowerInput>();
  for (const ECS::EntityID entity : view) {
    PowerInput &input = view.get<PowerInput>(entity);
    
    const Pos pos = view.get<Position>(entity).pos;
    const Math::DirBits inputSides = input.sides;
    
    input.states = Math::DirBits::NONE;
    
    // for each neighbor
    for (const Math::Dir dir : Math::DIR_RANGE) {
      // this side must be an input
      if (!Math::test(inputSides, dir)) {
        continue;
      }
      
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
        const Math::DirBits outputSides = registry.get<PowerOutput>(targetID).sides;
        if (!Math::test(outputSides, Math::opposite(dir))) {
          continue;
        }
        const bool power = registry.get<Power>(targetID).prev;
        input.states = Math::change(input.states, dir, power);
      } else if (registry.has<Wire>(targetID)) {
        const Wire wire = registry.get<Wire>(targetID);
        if (!Math::test(wire.sides, Math::opposite(dir))) {
          continue;
        }
        const bool power = registry.get<Power>(targetID).prev;
        input.states = Math::change(input.states, dir, power);
      } else if (registry.has<CrossWire>(targetID)) {
        const CrossWire cross = registry.get<CrossWire>(targetID);
        const bool power = Math::isVert(dir) ? cross.vert.prev : cross.hori.prev;
        input.states = Math::change(input.states, dir, power);
      }
    }
  }
}
