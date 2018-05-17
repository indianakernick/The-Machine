//
//  radioactivity detector component.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef radioactivity_detector_component_hpp
#define radioactivity_detector_component_hpp

#include <Simpleton/Grid/dir.hpp>
#include <Simpleton/Data/json.hpp>

struct RadioactivityDetector {
  Grid::Dir side;
  
  static void init(RadioactivityDetector &comp, const json &node) {
    comp.side = static_cast<Grid::Dir>(node.at("side").get<Grid::DirType>());
  }
};

#endif
