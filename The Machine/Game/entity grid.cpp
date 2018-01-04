//
//  entity grid.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "entity grid.hpp"

EntityGrid::EntityGrid(const Pos size)
  : mTiles(size.x * size.y, NULL_TILE), mSize(size) {}

Tile &EntityGrid::operator[](const Pos pos) {
  return mTiles[pos.y * mSize.x + pos.x];
}

Tile EntityGrid::operator[](const Pos pos) const {
  return mTiles[pos.y * mSize.x + pos.x];
}

Tile &EntityGrid::at(const Pos pos) {
  checkPosRange(pos);
  return (*this)[pos];
}

Tile EntityGrid::at(const Pos pos) const {
  checkPosRange(pos);
  return (*this)[pos];
}

Pos EntityGrid::size() const {
  return mSize;
}

void EntityGrid::checkPosRange(const Pos pos) const {
  if (pos.x > mSize.x || pos.y > mSize.y) {
    throw std::range_error("Pos out of range");
  }
}
