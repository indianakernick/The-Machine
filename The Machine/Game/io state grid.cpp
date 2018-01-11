//
//  io state grid.cpp
//  The Machine
//
//  Created by Indi Kernick on 11/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "io state grid.hpp"

IOStateGrid::IOStateGrid()
  : mSize(0, 0) {}

IOStateGrid::IOStateGrid(const Pos size)
  : vert(size.x * (size.y + 1)), hori((size.x + 1) * size.y), mSize(size) {}

void IOStateGrid::resize(const Pos size) {
  mSize = size;
  vert.resize(size.x * (size.y + 1));
  hori.resize((size.x + 1) * size.y);
}

Pos IOStateGrid::size() const {
  return mSize;
}

bool IOStateGrid::outOfRange(const Pos pos) const {
  return pos.x >= mSize.x || pos.y >= mSize.y;
}

void IOStateGrid::clear() {
  std::fill(vert.begin(), vert.end(), false);
  std::fill(hori.begin(), hori.end(), false);
}

void IOStateGrid::set(const Pos pos, const Math::Dir dir, const bool value) {
  if (Math::isVert(dir)) {
    const size_t positive = dir == Math::Dir::UP;
    const size_t index = (pos.y + positive) * mSize.x + pos.x;
    vert[index] = value;
  } else {
    const size_t positive = dir == Math::Dir::RIGHT;
    const size_t index = pos.y * (mSize.x + 1) + (pos.x + positive);
    hori[index] = value;
  }
}

bool IOStateGrid::get(const Pos pos, const Math::Dir dir) const {
  if (Math::isVert(dir)) {
    const size_t positive = dir == Math::Dir::UP;
    const size_t index = (pos.y + positive) * mSize.x + pos.x;
    return vert[index];
  } else {
    const size_t positive = dir == Math::Dir::RIGHT;
    const size_t index = pos.y * (mSize.x + 1) + (pos.x + positive);
    return hori[index];
  }
}
