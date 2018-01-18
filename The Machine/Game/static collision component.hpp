//
//  static collision component.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef static_collision_component_hpp
#define static_collision_component_hpp

#include <cstdint>
#include <Simpleton/Data/json.hpp>

struct StaticCollision {
  uint32_t accepts;
  
  static void init(StaticCollision &comp, const json &node) {
    Data::get(comp.accepts, node, "accepts");
  }
};

#endif
