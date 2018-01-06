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

void pistonSystem(ECS::Registry &registry) {
  auto view = registry.view<Power, Piston, Position, Movement>();
  for (const ECS::EntityID entity : view) {
    const Pos pos = view.get<Position>(entity).pos;
    const Piston piston = view.get<Piston>(entity);
    const bool extended = piston.basePos == pos;
    const bool powered = view.get<Power>(entity).prev;
    
    if (!extended && powered) {
      view.get<Movement>(entity).desiredDir = piston.dir;
    } else if (extended && !powered) {
      view.get<Movement>(entity).desiredDir = Math::opposite(piston.dir);
    }
  }
}
