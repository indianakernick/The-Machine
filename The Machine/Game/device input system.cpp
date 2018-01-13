//
//  device input system.cpp
//  The Machine
//
//  Created by Indi Kernick on 11/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "device input system.hpp"

#include "dir to vec.hpp"
#include "power component.hpp"
#include "device component.hpp"
#include "position component.hpp"
#include "cross wire component.hpp"
#include "power input component.hpp"
#include "power output component.hpp"

void deviceInputSystem(ECS::Registry &registry, const EntityGrid &grid) {
  auto view = registry.view<Power, Device, Position, PowerInput>();
  
  for (const ECS::EntityID entity : view) {
    const Pos pos = view.get<Position>(entity).pos;
    const Math::DirBits inputSides = view.get<PowerInput>(entity).sides;
    
    bool power = false;
    
    // for each neighbor
    for (const Math::Dir dir : Math::DIR_RANGE) {
      // this side must be an input
      if (!Math::test(inputSides, dir)) {
        continue;
      }
      
      const Pos targetPos = pos + ToVec::conv(dir);
      if (grid.outOfRange(targetPos)) {
        continue;
      }
      
      const ECS::EntityID targetID = grid[targetPos].staticID;
      if (targetID == ECS::NULL_ENTITY) {
        continue;
      }
      
      if (!registry.has<PowerOutput>(targetID)) {
        continue;
      }
      
      const Math::DirBits outputSides = registry.get<PowerOutput>(targetID).sides;
      if (!Math::test(outputSides, Math::opposite(dir))) {
        continue;
      }
      
      if (registry.has<Power>(targetID)) {
        power = power || registry.get<Power>(targetID).prev;
      } else if (registry.has<CrossWire>(targetID)) {
        const CrossWire cross = registry.get<CrossWire>(targetID);
        if (Math::isVert(dir)) {
          power = power || cross.vert.prev;
        } else {
          power = power || cross.hori.prev;
        }
      }
    }
    
    view.get<Power>(entity).curr = power;
  }
}
