//
//  delay component.hpp
//  The Machine
//
//  Created by Indi Kernick on 13/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef delay_component_hpp
#define delay_component_hpp

#include <Simpleton/Data/json.hpp>

struct Delay {
  enum class State {
    LOW,
    RISE,
    HIGH,
    FALL
  };

  unsigned length;
  unsigned counter = 0;
  State state = State::LOW;
  
  static void init(Delay &comp, const json &node) {
    Data::get(comp.length, node, "length");
  }
};

#endif
