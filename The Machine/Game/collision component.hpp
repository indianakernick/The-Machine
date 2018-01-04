//
//  collision component.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef collision_component_hpp
#define collision_component_hpp

#include <cstdint>

struct Collision {
  uint32_t typeBit;
  uint32_t pushedBy;
  uint32_t accepts;
};

#endif
