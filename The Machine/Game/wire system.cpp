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
#include "device component.hpp"
#include "position component.hpp"
#include "cross wire component.hpp"
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
    
    if (registry.has<Wire>(entity)) {
      // wire must be unpowered
      Power &power = registry.get<Power>(entity);
      if (power.curr) {
        return;
      }
      power.curr = true;
      
      Wire &wire = registry.get<Wire>(entity);
      for (const Math::Dir dir : Math::DIR_RANGE) {
        if (Math::test(wire.sides, dir)) {
          propagatePower(registry, grid, pos + ToVec::conv(dir), dir);
        }
      }
    } else if (registry.has<CrossWire>(entity)) {
      CrossWire &cross = registry.get<CrossWire>(entity);
      if (Math::isVert(fromPrev)) {
        if (cross.vert.curr) {
          return;
        }
        cross.vert.curr = true;
      } else {
        if (cross.hori.curr) {
          return;
        }
        cross.hori.curr = true;
      }
      propagatePower(registry, grid, pos + ToVec::conv(fromPrev), fromPrev);
    }
  }
}

void wireSystem(ECS::Registry &registry, const EntityGrid &grid) {
  const auto outputView = registry.view<Power, Device, Position, PowerOutput>();
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
