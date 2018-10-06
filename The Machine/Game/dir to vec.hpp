//
//  dir to vec.hpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef dir_to_vec_hpp
#define dir_to_vec_hpp

#include "position type.hpp"
#include <Simpleton/Grid/dir.hpp>

constexpr Grid::ToVec<Coord, Grid::Dir::right, Grid::Dir::up> toVec{};
constexpr Grid::ToVec<float, Grid::Dir::right, Grid::Dir::up> toFloatVec{};

#endif
