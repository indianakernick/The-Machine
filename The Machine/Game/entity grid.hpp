//
//  entity grid.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef entity_grid_hpp
#define entity_grid_hpp

#include "types.hpp"
#include <Simpleton/ECS/registry.hpp>

struct Tile {
  ECS::EntityID staticID;
  ECS::EntityID dynamicID;
};

constexpr Tile NULL_TILE = {ECS::NULL_ENTITY, ECS::NULL_ENTITY};

using Tiles = std::vector<Tile>;

class EntityGrid {
public:
  explicit EntityGrid(Pos);

  // using an object instead of an index in `operator[]` is a little strange
  // but it makes it obvious to the caller that `operator[]` doesn't do range
  // checking but `at` does
  Tile &operator[](Pos);
  Tile operator[](Pos) const;
  Tile &at(Pos);
  Tile at(Pos) const;

  Pos size() const;
  
private:
  Tiles mTiles;
  Pos mSize;
  
  void checkPosRange(Pos) const;
};

#endif
