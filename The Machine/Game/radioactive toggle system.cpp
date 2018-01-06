//
//  radioactive toggle system.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "radioactive toggle system.hpp"

#include "dir to vec.hpp"
#include "power component.hpp"
#include "position component.hpp"
#include "radioactivity component.hpp"
#include "radioactive toggle component.hpp"

void radioactiveToggleSystem(ECS::Registry &registry, const EntityGrid &grid) {
  auto view = registry.view<Power, Position, RadioactiveToggle>();
  for (const ECS::EntityID entity : view) {
    const Power power = view.get<Power>(entity);
    //enabled on the falling edge
    if (!(power.prev && !power.curr)) {
      continue;
    }
    
    const Pos pos = view.get<Position>(entity).pos;
    const Math::Dir side = view.get<RadioactiveToggle>(entity).side;
    const Pos targetPos = pos + ToVec::conv(side);
    
    if (grid.outOfRange(targetPos)) {
      continue;
    }
    
    const ECS::EntityID targetID = grid[targetPos].dynamicID;
    if (targetID == ECS::NULL_ENTITY) {
      continue;
    }
    
    if (!registry.has<Radioactivity>(targetID)) {
      continue;
    }
    
    Radioactivity &radioactivity = registry.get<Radioactivity>(targetID);
    radioactivity.curr = !radioactivity.prev;
  }
}
