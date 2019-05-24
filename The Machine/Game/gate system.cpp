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
        return input.states == input.sides;
      case GateFun::OR:
        return Grid::any(input.states);
      case GateFun::XOR:
        return Grid::count(input.states) == 1;
      case GateFun::NOT:
        if (Grid::count(input.sides) == 1) {
          return Grid::none(input.states);
        } else {
          throw std::runtime_error("NOT function expects single input");
        }
      case GateFun::NAND:
        return input.states != input.sides;
      case GateFun::NOR:
        return Grid::none(input.states);
      case GateFun::XNOR:
        return Grid::count(input.states) != 1;
      case GateFun::IDENTITY:
        if (Grid::count(input.sides) == 1) {
          return Grid::any(input.states);
        } else {
          throw std::runtime_error("IDENTITY function expects single input");
        }
    }
  }
}

void gateSystem(entt::registry &registry) {
  auto view = registry.view<Gate, Power, PowerInput>();
  
  for (const entt::entity entity : view) {
    const PowerInput input = view.get<PowerInput>(entity);
    const GateFun gateFun = view.get<Gate>(entity).fun;
    view.get<Power>(entity).curr = calcGateFun(input, gateFun);
  }
}
