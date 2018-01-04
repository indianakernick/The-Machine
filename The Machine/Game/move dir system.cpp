//
//  move dir system.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "move dir system.hpp"

#include "movement component.hpp"
#include "static collision component.hpp"
#include "dynamic collision component.hpp"

namespace {
  void clearRealDir(ECS::Registry &registry) {
    auto view = registry.view<Movement>();
    for (const ECS::EntityID entity : view) {
      view.get(entity).realDir = Math::Dir::NONE;
    }
  }
  
  using ToVec = Math::ToVec<Coord, Math::Dir::RIGHT, Math::Dir::UP>;

  bool isMovingToPosFromSide(
    const EntityGrid &grid,
    const entt::View<ECS::EntityID, Movement> movementView,
    const Pos pos,
    const Math::Dir side
  ) {
    const Pos sideVec = ToVec::conv(side);
    if (pos.x == 0 && sideVec.x == Coord(-1)) {
      return false;
    } else if (pos.y == 0 && sideVec.y == Coord(-1)) {
      return false;
    } else {
      const Pos fromPos = pos + sideVec;
      const ECS::EntityID fromID = grid[fromPos].dynamicID;
      if (fromID == ECS::NULL_ENTITY) {
        return false;
      } else {
        return (movementView.get(fromID).realDir != Math::opposite(side));
      }
    }
  };
}

void moveDirSystem(ECS::Registry &registry, const EntityGrid &grid) {
  clearRealDir(registry);
  
  auto movementView = registry.view<Movement>();
  const auto staticView = registry.view<StaticCollision>();
  const auto dynamicView = registry.view<DynamicCollision>();
  const Pos size = grid.size();
  Pos pos;
  
  for (pos.y = 0; pos.y != size.y; ++pos.y) {
    for (pos.x = 0; pos.x != size.x; ++pos.x) {
      const ECS::EntityID entity = grid[pos].dynamicID;
      if (entity == ECS::NULL_ENTITY) {
        continue;
      }
      Movement &movement = movementView.get(entity);
      if (movement.desiredDir == Math::Dir::NONE) {
        continue;
      }
      if (movement.realDir != Math::Dir::NONE) {
        continue;
      }
      const Pos desiredPos = pos + ToVec::conv(movement.desiredDir);
      const Tile desiredTile = grid[desiredPos];
      
      const auto desiredAccepts = staticView.get(desiredTile.staticID).accepts;
      const bool staticOK = desiredAccepts & dynamicView.get(entity).type;
      
      const bool leftOK = !isMovingToPosFromSide(grid, movementView, desiredPos, Math::Dir::LEFT);
      const bool downOK = !isMovingToPosFromSide(grid, movementView, desiredPos, Math::Dir::DOWN);
    }
  }
}
