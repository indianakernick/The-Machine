//
//  dynamic collision component.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef dynamic_collision_component_hpp
#define dynamic_collision_component_hpp

#include <cstdint>

struct DynamicCollision {
  uint32_t type;
  uint32_t pushedBy;
};

#endif
