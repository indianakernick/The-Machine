//
//  power input system.cpp
//  The Machine
//
//  Created by Indi Kernick on 10/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "power input system.hpp"

#include "dir to vec.hpp"
#include "wire component.hpp"
#include "power component.hpp"
#include "position component.hpp"
#include "power input component.hpp"
#include "power output component.hpp"

void powerInputSystem(ECS::Registry &registry, const EntityGrid &grid) {
  auto view = registry.view<Power, Position, PowerInput>();
  const auto outputView = registry.view<PowerOutput>();
  const auto powerView = registry.view<Power>();
  for (const ECS::EntityID entity : view) {
    PowerInput &input = view.get<PowerInput>(entity);
    
    const Pos pos = view.get<Position>(entity).pos;
    const Math::DirBits inputSides = input.sides;
    
    input.states = Math::DirBits::NONE;
    
    // for each neighbor
    for (const Math::Dir dir : Math::DIR_RANGE) {
      // this side must be an input
      if (!Math::test(inputSides, dir)) {
        continue;
      }
      
      // taking input from a tile outside of the map returns false
      const Pos targetPos = pos + ToVec::conv(dir);
      if (grid.outOfRange(targetPos)) {
        continue;
      }
      
      // taking input from a tile without a static entity returns false
      const ECS::EntityID targetID = grid[targetPos].staticID;
      if (targetID == ECS::NULL_ENTITY) {
        continue;
      }
      
      // taking input from an entity without an output returns false
      if (registry.has<PowerOutput>(targetID)) {
        // taking input from an entity without an output in the opposite dir returns false
        const Math::DirBits outputSides = outputView.get(targetID).sides;
        if (!Math::test(outputSides, Math::opposite(dir))) {
          continue;
        }
        
        input.states = Math::change(input.states, dir, powerView.get(targetID).prev);
      } else if (registry.has<Wire>(targetID)) {
        const Wire wire = registry.get<Wire>(targetID);
        if (!Math::test(wire.sides, Math::opposite(dir))) {
          continue;
        }
        if (wire.cross) {
          const bool power = Math::isHori(dir) ? wire.horiPowered : wire.vertPowered;
          input.states = Math::change(input.states, dir, power);
        } else {
          input.states = Math::change(input.states, dir, powerView.get(targetID).prev);
        }
      }
    }
    
    if (!registry.has<PowerOutput>(entity)) {
      view.get<Power>(entity).curr = Math::any(input.states);
    }
  }
}