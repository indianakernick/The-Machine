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
#include <Simpleton/Grid/dir bits.hpp>

struct PowerOutput {
  Grid::DirBits sides;
  
  static void init(PowerOutput &comp, const json &node) {
    comp.sides = static_cast<Grid::DirBits>(node.at("sides").get<Grid::DirType>());
  }
};

#endif
