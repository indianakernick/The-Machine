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
#include <Simpleton/Data/json.hpp>

struct Piston {
  Pos basePos;
  Math::Dir dir;
  
  static void init(Piston &comp, const json &node) {
    Data::get(comp.basePos, node, "base_pos");
    comp.dir = static_cast<Math::Dir>(node.at("dir").get<Math::DirType>());
  }
};

#endif
