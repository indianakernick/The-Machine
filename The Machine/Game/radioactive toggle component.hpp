//
//  radioactive toggle component.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef radioactive_toggle_component_hpp
#define radioactive_toggle_component_hpp

#include <Simpleton/Math/dir.hpp>
#include <Simpleton/Data/json.hpp>

struct RadioactiveToggle {
  Math::Dir side;
  
  static void init(RadioactiveToggle &comp, const json &node) {
    comp.side = static_cast<Math::Dir>(node.at("side").get<Math::DirType>());
  }
};

#endif
