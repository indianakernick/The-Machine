//
//  gate system.cpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "gate system.hpp"

#include "gate component.hpp"
#include "power component.hpp"
#include "power input component.hpp"

namespace {
  bool calcGateFun(const PowerInput input, const GateFun fun) {
    switch (fun) {
      case GateFun::AND:
        return Math::all(input.states);
      case GateFun::OR:
        return Math::any(input.states);
      case GateFun::XOR:
        return Math::count(input.states) == 1;
      case GateFun::NOT:
        if (Math::count(input.sides) == 1) {
          return Math::count(input.states) == 0;
        } else {
          throw std::runtime_error("NOT function expects single input");
        }
      case GateFun::NAND:
        return Math::all(Math::opposite(input.states));
      case GateFun::NOR:
        return Math::any(Math::opposite(input.states));
      case GateFun::XNOR:
        return Math::count(input.states) == 3;
      case GateFun::IDENTITY:
        if (Math::count(input.sides) == 1) {
          return Math::count(input.states) != 0;
        } else {
          throw std::runtime_error("IDENTITY function expects single input");
        }
    }
  }
}

void gateSystem(ECS::Registry &registry) {
  auto view = registry.view<Gate, Power, PowerInput>();
  for (const ECS::EntityID entity : view) {
    const PowerInput input = view.get<PowerInput>(entity);
    const GateFun gateFun = view.get<Gate>(entity).fun;
    view.get<Power>(entity).curr = calcGateFun(input, gateFun);
  }
}
