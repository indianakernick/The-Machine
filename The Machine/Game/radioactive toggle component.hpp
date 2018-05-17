//
//  radioactive toggle component.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef radioactive_toggle_component_hpp
#define radioactive_toggle_component_hpp

#include <Simpleton/Grid/dir.hpp>
#include <Simpleton/Data/json.hpp>

struct RadioactiveToggle {
  Grid::Dir side;
  
  static void init(RadioactiveToggle &comp, const json &node) {
    comp.side = static_cast<Grid::Dir>(node.at("side").get<Grid::DirType>());
  }
};

#endif
