//
//  position component.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef position_component_hpp
#define position_component_hpp

#include "position type.hpp"
#include <Simpleton/Data/json.hpp>

struct Position {
  Pos pos;
  
  static void init(Position &comp, const json &node) {
    comp.pos = node.get<Pos>();
  }
};

#endif
