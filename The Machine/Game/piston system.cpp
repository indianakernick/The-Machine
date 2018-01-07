//
//  piston system.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "piston system.hpp"

#include "power component.hpp"
#include "piston component.hpp"
#include "position component.hpp"
#include "movement component.hpp"

void pistonSystem(ECS::Registry &registry, const EntityGrid &grid) {
  const auto baseView = registry.view<Power>();
  auto headView = registry.view<Piston, Position, Movement>();
  for (const ECS::EntityID entity : headView) {
    const Pos pos = headView.get<Position>(entity).pos;
    const ECS::EntityID baseID = grid[pos].staticID;
    const Piston piston = headView.get<Piston>(entity);
    const bool extended = piston.basePos == pos;
    const bool powered = baseView.get(baseID).curr;
    
    if (!extended && powered) {
      headView.get<Movement>(entity).desiredDir = piston.dir;
    } else if (extended && !powered) {
      headView.get<Movement>(entity).desiredDir = Math::opposite(piston.dir);
    }
  }
}
