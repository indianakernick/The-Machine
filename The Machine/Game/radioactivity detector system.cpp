//
//  radioactivity detector system.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "radioactivity detector system.hpp"

#include "dir to vec.hpp"
#include "power component.hpp"
#include "position component.hpp"
#include "radioactivity component.hpp"
#include "radioactivity detector component.hpp"

void radioactivityDetectorSystem(ECS::Registry &registry, const EntityGrid &grid) {
  auto view = registry.view<Power, Position, RadioactivityDetector>();
  for (const ECS::EntityID entity : view) {
    const Pos pos = view.get<Position>(entity).pos;
    const Grid::Dir side = view.get<RadioactivityDetector>(entity).side;
    const Pos targetPos = pos + ToVec::conv(side);
    
    if (grid.outOfRange(targetPos)) {
      continue;
    }
    
    const ECS::EntityID targetID = grid[targetPos].dynamicID;
    if (targetID == entt::null) {
      continue;
    }
    
    if (!registry.has<Radioactivity>(targetID)) {
      continue;
    }
    
    const bool radioactive = registry.get<Radioactivity>(targetID).prev;
    view.get<Power>(entity).curr = radioactive;
  }
}
