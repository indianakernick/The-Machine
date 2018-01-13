//
//  device input system.cpp
//  The Machine
//
//  Created by Indi Kernick on 11/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "device input system.hpp"

#include "power component.hpp"
#include "device component.hpp"
#include "power input component.hpp"

void deviceInputSystem(ECS::Registry &registry) {
  auto view = registry.view<Power, Device, PowerInput>();
  for (const ECS::EntityID entity : view) {
    const Math::DirBits inputStates = view.get<PowerInput>(entity).states;
    view.get<Power>(entity).curr = Math::any(inputStates);
  }
}
