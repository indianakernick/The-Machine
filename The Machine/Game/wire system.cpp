//
//  wire system.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "wire system.hpp"

#include "dir to vec.hpp"
#include "wire component.hpp"
#include "power component.hpp"
#include "position component.hpp"
#include "power input component.hpp"
#include "power output component.hpp"

namespace {
  void propagatePower(
    ECS::Registry &registry,
    const EntityGrid &grid,
    const Pos pos,
    const Math::Dir fromPrev // a direction pointing away from the previous wire
  ) {
    // tile must be inside world
    if (grid.outOfRange(pos)) {
      return;
    }
    
    // tile must have a static entity
    const ECS::EntityID entity = grid[pos].staticID;
    if (entity == ECS::NULL_ENTITY) {
      return;
    }
    
    // tile must be wire
    if (!registry.has<Wire>(entity)) {
      return;
    }
    
    // wire must be unpowered
    Power &power = registry.get<Power>(entity);
    if (power.curr) {
      return;
    }
    
    power.curr = true;
    
    Wire &wire = registry.get<Wire>(entity);
    if (wire.cross) {
      if (Math::isHori(fromPrev)) {
        wire.horiPowered = true;
      } else {
        wire.vertPowered = true;
      }
    
      propagatePower(registry, grid, pos + ToVec::conv(fromPrev), fromPrev);
    } else {
      for (const Math::Dir dir : Math::DIR_RANGE) {
        if (Math::test(wire.sides, dir)) {
          propagatePower(registry, grid, pos + ToVec::conv(dir), dir);
        }
      }
    }
  }
}

void wireSystem(ECS::Registry &registry, const EntityGrid &grid) {
  const auto outputView = registry.view<Power, Position, PowerOutput>();
  for (const ECS::EntityID entity : outputView) {
    if (!outputView.get<Power>(entity).prev) {
      continue;
    }
    
    const Pos pos = outputView.get<Position>(entity).pos;
    const Math::DirBits outputSides = outputView.get<PowerOutput>(entity).sides;
    
    for (const Math::Dir dir : Math::DIR_RANGE) {
      if (Math::test(outputSides, dir)) {
        propagatePower(registry, grid, pos + ToVec::conv(dir), dir);
      }
    }
  }
}
