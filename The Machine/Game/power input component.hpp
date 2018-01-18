//
//  power input component.hpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef power_input_component_hpp
#define power_input_component_hpp

#include <Simpleton/Data/json.hpp>
#include <Simpleton/Math/dir bits.hpp>

struct PowerInput {
  Math::DirBits sides;
  Math::DirBits states = Math::DirBits::NONE;
  
  static void init(PowerInput &comp, const json &node) {
    comp.sides = static_cast<Math::DirBits>(node.at("sides").get<Math::DirType>());
  }
};

#endif
