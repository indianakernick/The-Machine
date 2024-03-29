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

void radioactiveToggleSystem(entt::registry &registry, const EntityGrid &grid) {
  auto view = registry.view<Power, Position, RadioactiveToggle>();
  for (const entt::entity entity : view) {
    const Power power = view.get<Power>(entity);
    //enabled on the falling edge
    if (!(power.prev && !power.curr)) {
      continue;
    }
    
    const Pos pos = view.get<Position>(entity).pos;
    const Grid::Dir side = view.get<RadioactiveToggle>(entity).side;
    const Pos targetPos = pos + toVec(side);
    
    if (grid.outOfRange(targetPos)) {
      continue;
    }
    
    const entt::entity targetID = grid[targetPos].dynamicID;
    if (targetID == entt::null) {
      continue;
    }
    
    if (!registry.has<Radioactivity>(targetID)) {
      continue;
    }
    
    Radioactivity &radioactivity = registry.get<Radioactivity>(targetID);
    radioactivity.curr = !radioactivity.prev;
  }
}
