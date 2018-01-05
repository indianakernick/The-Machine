//
//  shift power system.cpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "shift power system.hpp"

#include "power component.hpp"

void shiftPowerSystem(ECS::Registry &registry) {
  auto view = registry.view<Power>();
  for (const ECS::EntityID entity : view) {
    Power &power = view.get(entity);
    power.prev = power.curr;
  }
}
