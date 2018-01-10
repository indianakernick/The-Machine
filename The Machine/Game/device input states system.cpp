//
//  device input states system.cpp
//  The Machine
//
//  Created by Indi Kernick on 10/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "device input states system.hpp"

#include "power component.hpp"
#include "device component.hpp"
#include "power input component.hpp"

void deviceInputStatesSystem(ECS::Registry &registry) {
  auto view = registry.view<Power, Device, PowerInput>();
  for (const ECS::EntityID entity : view) {
    const bool power = Math::any(view.get<PowerInput>(entity).states);
    view.get<Power>(entity).curr = power;
  }
}
