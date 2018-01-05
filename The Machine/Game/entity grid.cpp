//
//  entity grid.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "entity grid.hpp"

EntityGrid::EntityGrid()
  : mSize(0, 0) {}

EntityGrid::EntityGrid(const Pos size)
  : mTiles(size.x * size.y, NULL_TILE), mSize(size) {}

void EntityGrid::resize(const Pos newSize) {
  mSize = newSize;
  mTiles.resize(newSize.x * newSize.y, NULL_TILE);
}

Tile &EntityGrid::operator[](const Pos pos) {
  return mTiles[pos.y * mSize.x + pos.x];
}

Tile EntityGrid::operator[](const Pos pos) const {
  return mTiles[pos.y * mSize.x + pos.x];
}

Tile &EntityGrid::at(const Pos pos) {
  checkRange(pos);
  return (*this)[pos];
}

Tile EntityGrid::at(const Pos pos) const {
  checkRange(pos);
  return (*this)[pos];
}

Pos EntityGrid::size() const {
  return mSize;
}

bool EntityGrid::outOfRange(const Pos pos) const {
  return pos.x >= mSize.x || pos.y >= mSize.y;
}

Tile &EntityGrid::operator[](const size_t i) {
  return mTiles[i];
}

Tile EntityGrid::operator[](const size_t i) const {
  return mTiles[i];
}

Tile &EntityGrid::at(const size_t i) {
  checkRange(i);
  return (*this)[i];
}

Tile EntityGrid::at(const size_t i) const {
  checkRange(i);
  return (*this)[i];
}

size_t EntityGrid::length() const {
  return mTiles.size();
}

bool EntityGrid::outOfRange(const size_t i) const {
  return i >= mTiles.size();
}

void EntityGrid::checkRange(const Pos pos) const {
  if (outOfRange(pos)) {
    throw std::range_error("Pos out of range");
  }
}

void EntityGrid::checkRange(const size_t i) const {
  if (outOfRange(i)) {
    throw std::range_error("Index out of range");
  }
}
