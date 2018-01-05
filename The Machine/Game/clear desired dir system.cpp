//
//  clear desired dir system.cpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "clear desired dir system.hpp"

#include "movement component.hpp"

void clearDesiredDirSystem(ECS::Registry &registry) {
  auto view = registry.view<Movement>();
  for (const ECS::EntityID entity : view) {
    view.get(entity).desiredDir = Math::Dir::NONE;
  }
}
