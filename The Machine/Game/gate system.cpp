//
//  gate system.cpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "gate system.hpp"

#include "dir to vec.hpp"
#include "gate component.hpp"
#include "power component.hpp"
#include "position component.hpp"
#include "power input component.hpp"
#include "power output component.hpp"

namespace {
  auto equals(const bool val) {
    return [val] (const bool value) -> bool {
      return val == value;
    };
  }

  bool calcGateFun(const std::vector<bool> inputs, const GateFun fun) {
    switch (fun) {
      case GateFun::AND:
        return std::all_of(inputs.cbegin(), inputs.cend(), equals(true));
      case GateFun::OR:
        return std::any_of(inputs.cbegin(), inputs.cend(), equals(true));
      case GateFun::XOR:
        return std::count(inputs.cbegin(), inputs.cend(), true) == 1;
      case GateFun::NOT:
        if (inputs.size() != 1) {
          throw std::runtime_error("NOT function expects single input");
        } else {
          return !inputs[0];
        }
      case GateFun::NAND:
        return std::all_of(inputs.cbegin(), inputs.cend(), equals(false));
      case GateFun::NOR:
        return std::any_of(inputs.cbegin(), inputs.cend(), equals(false));
      case GateFun::XNOR:
        return std::count(inputs.cbegin(), inputs.cend(), false) == 1;
      case GateFun::IDENTITY:
        if (inputs.size() != 1) {
          throw std::runtime_error("IDENTITY function expects single input");
        } else {
          return inputs[0];
        }
    }
  }
}

void gateSystem(ECS::Registry &registry, const EntityGrid &grid) {
  static std::vector<bool> inputStates;
  
  auto gateView = registry.view<Gate, Power, Position>();
  const auto inputView = registry.view<PowerInput>();
  const auto outputView = registry.view<PowerOutput>();
  auto powerView = registry.view<Power>();
  
  for (const ECS::EntityID entity : gateView) {
    const Pos pos = gateView.get<Position>(entity).pos;
    const Math::DirBits inputSides = inputView.get(entity).sides;
    
    inputStates.clear();
    
    // for each neighbor
    for (const Math::Dir dir : Math::DIR_RANGE) {
      // this side must be an input
      if (!Math::test(inputSides, dir)) {
        continue;
      }
      
      // taking input from a tile outside of the map returns false
      const Pos targetPos = pos + ToVec::conv(dir);
      if (grid.outOfRange(targetPos)) {
        inputStates.push_back(false);
        continue;
      }
      
      // taking input from an entity without an output returns false
      const ECS::EntityID targetID = grid[targetPos].staticID;
      if (targetID == ECS::NULL_ENTITY) {
        inputStates.push_back(false);
        continue;
      }
      
      if (!registry.has<PowerOutput>(targetID)) {
        inputStates.push_back(false);
        continue;
      }
      
      // taking input from an entity without an output in the opposite dir returns false
      const Math::DirBits outputSides = outputView.get(targetID).sides;
      if (!Math::test(outputSides, Math::opposite(dir))) {
        inputStates.push_back(false);
        continue;
      }
      
      inputStates.push_back(powerView.get(targetID).prev);
    }
    
    const GateFun gateFun = gateView.get<Gate>(entity).fun;
    powerView.get(entity).curr = calcGateFun(inputStates, gateFun);
  }
}
