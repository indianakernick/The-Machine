//
//  weight component.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef weight_component_hpp
#define weight_component_hpp

#include <Simpleton/Data/json.hpp>

struct Weight {
  bool heavy;
  
  static void init(Weight &comp, const json &node) {
    Data::get(comp.heavy, node, "heavy");
  }
};

#endif
