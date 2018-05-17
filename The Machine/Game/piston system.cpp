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
  auto headView = registry.view<Piston, Position, Movement>();
  for (const ECS::EntityID entity : headView) {
    const Pos pos = headView.get<Position>(entity).pos;
    const Piston piston = headView.get<Piston>(entity);
    const ECS::EntityID baseID = grid[piston.basePos].staticID;
    const bool extended = piston.basePos != pos;
    const bool powered = registry.get<Power>(baseID).curr;
    
    if (not extended and powered) {
      headView.get<Movement>(entity).desiredDir = piston.dir;
    } else if (extended and not powered) {
      headView.get<Movement>(entity).desiredDir = Grid::opposite(piston.dir);
    }
  }
}
