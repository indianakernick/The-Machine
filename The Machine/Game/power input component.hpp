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
#include <Simpleton/Grid/dir bits.hpp>

struct PowerInput {
  Grid::DirBits sides;
  Grid::DirBits states = Grid::DirBits::none;
  
  static void init(PowerInput &comp, const json &node) {
    comp.sides = static_cast<Grid::DirBits>(node.at("sides").get<Grid::DirType>());
  }
};

#endif
