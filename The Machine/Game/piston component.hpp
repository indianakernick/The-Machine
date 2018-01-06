//
//  piston component.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef piston_component_hpp
#define piston_component_hpp

#include "position type.hpp"
#include <Simpleton/Math/dir.hpp>

struct Piston {
  Pos basePos;
  Math::Dir dir;
};

#endif
