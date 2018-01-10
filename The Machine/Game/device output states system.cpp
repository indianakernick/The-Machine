//
//  device output states system.cpp
//  The Machine
//
//  Created by Indi Kernick on 10/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "device output states system.hpp"

#include "power component.hpp"
#include "device component.hpp"
#include "power output component.hpp"

void deviceOutputStatesSystem(ECS::Registry &registry) {
  auto view = registry.view<Power, Device, PowerOutput>();
  for (const ECS::EntityID entity : view) {
    const bool power = view.get<Power>(entity).prev;
    PowerOutput &output = view.get<PowerOutput>(entity);
    output.states = power ? output.sides : Math::DirBits::NONE;
  }
}
