//
//  radioactivity component.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef radioactivity_component_hpp
#define radioactivity_component_hpp

#include <Simpleton/Data/json.hpp>

struct Radioactivity {
  bool prev;
  bool curr;
  
  static void init(Radioactivity &comp, const json &node) {
    Data::get(comp.prev, node, "enabled");
    comp.curr = comp.prev;
  }
};

#endif
