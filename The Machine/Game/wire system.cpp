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
#include "cross wire component.hpp"
#include "power input component.hpp"
#include "power output component.hpp"

namespace {
  void propagatePower(
    entt::registry &registry,
    const EntityGrid &grid,
    const Pos pos,
    const Grid::Dir fromPrev // a direction pointing away from the previous wire
  ) {
    // tile must be inside world
    if (grid.outOfRange(pos)) {
      return;
    }
    
    // tile must have a static entity
    const entt::entity entity = grid[pos].staticID;
    if (entity == entt::null) {
      return;
    }
    
    if (registry.has<Wire>(entity)) {
      const Wire wire = registry.get<Wire>(entity);
      if (!Grid::test(wire.sides, Grid::opposite(fromPrev))) {
        return;
      }
    
      Power &power = registry.get<Power>(entity);
      if (power.curr) {
        return;
      }
      power.curr = true;
      
      for (const Grid::Dir dir : Grid::dir_range) {
        if (Grid::test(wire.sides, dir)) {
          propagatePower(registry, grid, pos + toVec(dir), dir);
        }
      }
    } else if (registry.has<CrossWire>(entity)) {
      CrossWire &cross = registry.get<CrossWire>(entity);
      if (Grid::isVert(fromPrev)) {
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
      propagatePower(registry, grid, pos + toVec(fromPrev), fromPrev);
    }
  }
}

void wireSystem(entt::registry &registry, const EntityGrid &grid) {
  const auto outputView = registry.view<Power, Position, PowerOutput>();
  for (const entt::entity entity : outputView) {
    if (!outputView.get<Power>(entity).prev) {
      continue;
    }
    
    const Pos pos = outputView.get<Position>(entity).pos;
    const Grid::DirBits outputSides = outputView.get<PowerOutput>(entity).sides;
    
    for (const Grid::Dir dir : Grid::dir_range) {
      if (Grid::test(outputSides, dir)) {
        propagatePower(registry, grid, pos + toVec(dir), dir);
      }
    }
  }
}
