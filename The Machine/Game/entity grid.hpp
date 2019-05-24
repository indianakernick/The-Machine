//
//  entity grid.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef entity_grid_hpp
#define entity_grid_hpp

#include "position type.hpp"
#include <entt/entity/registry.hpp>

struct Tile {
  entt::entity staticID;
  entt::entity dynamicID;
};

constexpr Tile NULL_TILE = {entt::null, entt::null};

using Tiles = std::vector<Tile>;

class EntityGrid {
public:
  EntityGrid();
  explicit EntityGrid(Pos);
  EntityGrid(EntityGrid &&) = default;
  EntityGrid &operator=(EntityGrid &&) = default;

  void resize(Pos);

  // using an object instead of an index in `operator[]` is a little strange
  // but it makes it obvious to the caller that `operator[]` doesn't do range
  // checking but `at` does
  Tile &operator[](Pos);
  Tile operator[](Pos) const;
  Tile &at(Pos);
  Tile at(Pos) const;
  
  Pos size() const;
  bool outOfRange(Pos) const;
  
  Tile &operator[](size_t);
  Tile operator[](size_t) const;
  Tile &at(size_t);
  Tile at(size_t) const;
  
  size_t length() const;
  bool outOfRange(size_t) const;
  
private:
  Tiles mTiles;
  Pos mSize;
  
  void checkRange(Pos) const;
  void checkRange(size_t) const;
};

#endif
