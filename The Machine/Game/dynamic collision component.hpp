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
#include <Simpleton/Data/json.hpp>

struct DynamicCollision {
  uint32_t type;
  uint32_t pushedBy;
  
  static void init(DynamicCollision &comp, const json &node) {
    Data::get(comp.type, node, "type");
    Data::get(comp.pushedBy, node, "pushed_by");
  }
};

#endif
