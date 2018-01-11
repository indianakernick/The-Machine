//
//  io state grid.hpp
//  The Machine
//
//  Created by Indi Kernick on 11/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef io_state_grid_hpp
#define io_state_grid_hpp

#include <vector>
#include "position type.hpp"
#include <Simpleton/Math/dir.hpp>

class IOStateGrid {
public:
  IOStateGrid();
  explicit IOStateGrid(Pos);
  IOStateGrid(IOStateGrid &&) = default;
  IOStateGrid &operator=(IOStateGrid &&) = default;
  
  void resize(Pos);
  Pos size() const;
  bool outOfRange(Pos) const;
  
  void clear();
  
  void set(Pos, Math::Dir, bool);
  bool get(Pos, Math::Dir) const;

private:
  std::vector<bool> vert;
  std::vector<bool> hori;
  Pos mSize;
};

#endif
