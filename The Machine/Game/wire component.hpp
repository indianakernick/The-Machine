//
//  wire component.hpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef wire_component_hpp
#define wire_component_hpp

#include <Simpleton/Data/json.hpp>
#include <Simpleton/Math/dir bits.hpp>

struct Wire {
  Math::DirBits sides;
  
  static void init(Wire &comp, const json &node) {
    comp.sides = static_cast<Math::DirBits>(node.at("sides").get<Math::DirType>());
  }
};

#endif
