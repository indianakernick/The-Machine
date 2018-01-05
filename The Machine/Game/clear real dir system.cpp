//
//  clear real dir system.cpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "clear real dir system.hpp"

#include "movement component.hpp"

void clearRealDirSystem(ECS::Registry &registry) {
  auto view = registry.view<Movement>();
  for (const ECS::EntityID entity : view) {
    view.get(entity).realDir = Math::Dir::NONE;
  }
}
