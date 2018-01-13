//
//  power input system.cpp
//  The Machine
//
//  Created by Indi Kernick on 13/1/18.
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
  auto view = registry.view<PowerInput, Position>();
  
  for (const ECS::EntityID entity : view) {
    const Pos pos = view.get<Position>(entity).pos;
    PowerInput &input = view.get<PowerInput>(entity);
    input.states = Math::DirBits::NONE;
    
    for (const Math::Dir dir : Math::DIR_RANGE) {
      // this side must be an input
      if (!Math::test(input.sides, dir)) {
        continue;
      }
      
      // the target tile must be within the world
      const Pos targetPos = pos + ToVec::conv(dir);
      if (grid.outOfRange(targetPos)) {
        continue;
      }
      
      // the target tile must contain a static entity
      const ECS::EntityID targetID = grid[targetPos].staticID;
      if (targetID == ECS::NULL_ENTITY) {
        continue;
      }
      
      if (registry.has<PowerOutput>(targetID)) {
        // the target entity must have an output in the opposite direction
        const Math::DirBits outputSides = registry.get<PowerOutput>(targetID).sides;
        if (!Math::test(outputSides, Math::opposite(dir))) {
          continue;
        }
        
        // the target entity must have a power component
        if (!registry.has<Power>(targetID)) {
          continue;
        }
        
        const bool power = registry.get<Power>(targetID).prev;
        input.states = Math::change(input.states, dir, power);
      } else if (registry.has<Wire>(targetID)) {
        // the target entity must have a connection in the opposite direction
        const Math::DirBits wireSides = registry.get<Wire>(targetID).sides;
        if (!Math::test(wireSides, Math::opposite(dir))) {
          continue;
        }
        
        // the target entity must have a power component
        if (!registry.has<Power>(targetID)) {
          continue;
        }
        
        const bool power = registry.get<Power>(targetID).prev;
        input.states = Math::change(input.states, dir, power);
      } else if (registry.has<CrossWire>(targetID)) {
        const CrossWire cross = registry.get<CrossWire>(targetID);
        const bool power = (Math::isVert(dir) ? cross.vert : cross.hori).prev;
        input.states = Math::change(input.states, dir, power);
      }
    }
  }
}
