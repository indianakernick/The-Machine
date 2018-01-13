//
//  delay component.hpp
//  The Machine
//
//  Created by Indi Kernick on 13/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef delay_component_hpp
#define delay_component_hpp

struct Delay {
  enum class State {
    FALL = -1,
    NONE = 0,
    RISE = 1
  };

  unsigned length;
  unsigned counter = 0;
  State state = State::NONE;
};

#endif
