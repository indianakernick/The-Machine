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

using ToVec = Grid::ToVec<Coord, Grid::Dir::RIGHT, Grid::Dir::UP>;
using ToFloatVec = Grid::ToVec<float, ToVec::PLUS_X, ToVec::PLUS_Y>;

#endif
