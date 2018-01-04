//
//  init grid system.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "init grid system.hpp"

#include "position component.hpp"
#include "static collision component.hpp"
#include "dynamic collision component.hpp"

void initGridSystem(ECS::Registry &registry, EntityGrid &grid) {
  const auto staticView = registry.view<Position, StaticCollision>();
  const auto dynamicView = registry.view<Position, DynamicCollision>();
  
  for (const ECS::EntityID entity : staticView) {
    const Pos pos = staticView.get<Position>(entity).pos;
    ECS::EntityID &staticID = grid.at(pos).staticID;
    if (staticID == ECS::NULL_ENTITY) {
      staticID = entity;
    } else {
      throw std::runtime_error("Tried to initialize static entity that was already initialized");
    }
  }
  for (const ECS::EntityID entity : dynamicView) {
    const Pos pos = dynamicView.get<Position>(entity).pos;
    ECS::EntityID &dynamicID = grid.at(pos).dynamicID;
    if (dynamicID == ECS::NULL_ENTITY) {
      dynamicID = entity;
    } else {
      throw std::runtime_error("Tried to initialize dynamic entity that was already initialized");
    }
  }
}
