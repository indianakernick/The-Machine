//
//  move dir system.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "move dir system.hpp"

#include "dir to vec.hpp"
#include "movement component.hpp"
#include "static collision component.hpp"
#include "dynamic collision component.hpp"

namespace {
  ECS::EntityID getDynamic(const EntityGrid &grid, const Pos pos) {
    return grid.outOfRange(pos) ? entt::null : grid[pos].dynamicID;
  }

  bool isMovingToPosFromSide(
    ECS::Registry &registry,
    const EntityGrid &grid,
    const Pos pos,
    const Grid::Dir side
  ) {
    const ECS::EntityID fromID = getDynamic(grid, pos + toVec(side));
    if (fromID == entt::null) {
      return false;
    } else {
      return (registry.get<Movement>(fromID).realDir == Grid::opposite(side));
    }
  }
  
  bool moveInDir(
    ECS::Registry &registry,
    const EntityGrid &grid,
    const ECS::EntityID entity,
    const Pos pos,
    const Grid::Dir dir
  ) {
    const uint32_t type = registry.get<DynamicCollision>(entity).type;
    const Pos targetPos = pos + toVec(dir);
    
    // can't move past the edge of the map
    if (grid.outOfRange(targetPos)) {
      return false;
    }
    
    const Tile targetTile = grid[targetPos];
    
    // static entity in target tile must accept this type of dynamic entity
    if (targetTile.staticID != entt::null) {
      const uint32_t accepts = registry.get<StaticCollision>(targetTile.staticID).accepts;
      if (!(accepts & type)) {
        return false;
      }
    }
    
    // there can't be any dynamic entities moving into the target tile from the left
    if (isMovingToPosFromSide(registry, grid, targetPos, Grid::Dir::left)) {
      return false;
    }
    // there can't be any dynamic entities moving into the target tile from below
    if (isMovingToPosFromSide(registry, grid, targetPos, Grid::Dir::down)) {
      return false;
    }
    
    // if the target tile has a dynamic entity
    if (targetTile.dynamicID != entt::null) {
      // the dynamic entity must allow this entity to push it
      const uint32_t pushedBy = registry.get<DynamicCollision>(targetTile.dynamicID).pushedBy;
      if (!(pushedBy & type)) {
        return false;
      }
      // the dynamic entity must be able to move in the direction of this entity
      if (moveInDir(registry, grid, targetTile.dynamicID, targetPos, dir)) {
        registry.get<Movement>(entity).realDir = dir;
        return true;
      } else {
        return false;
      }
    } else {
      // there aren't any dynamic entities in the way
      registry.get<Movement>(entity).realDir = dir;
      return true;
    }
  }
}

void moveDirSystem(ECS::Registry &registry, const EntityGrid &grid) {
  const auto movementView = registry.view<Movement>();
  const Pos size = grid.size();
  Pos pos;
  
  for (pos.y = 0; pos.y != size.y; ++pos.y) {
    for (pos.x = 0; pos.x != size.x; ++pos.x) {
      const ECS::EntityID entity = grid[pos].dynamicID;
      if (entity == entt::null) {
        continue;
      }
      const Movement movement = movementView.get(entity);
      if (movement.desiredDir == Grid::Dir::none) {
        continue;
      }
      if (movement.realDir != Grid::Dir::none) {
        continue;
      }
      
      moveInDir(registry, grid, entity, pos, movement.desiredDir);
    }
  }
}
