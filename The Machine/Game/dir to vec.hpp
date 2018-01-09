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
#include <Simpleton/Math/dir.hpp>

using ToVec = Math::ToVec<Coord, Math::Dir::RIGHT, Math::Dir::UP>;
using ToFloatVec = Math::ToVec<float, ToVec::PLUS_X, ToVec::PLUS_Y>;

#endif
