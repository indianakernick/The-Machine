//
//  power output component.hpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef power_output_component_hpp
#define power_output_component_hpp

#include <Simpleton/Data/json.hpp>
#include <Simpleton/Math/dir bits.hpp>

struct PowerOutput {
  Math::DirBits sides;
  
  static void init(PowerOutput &comp, const json &node) {
    comp.sides = static_cast<Math::DirBits>(node.at("sides").get<Math::DirType>());
  }
};

#endif
