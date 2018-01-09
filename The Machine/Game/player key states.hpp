//
//  player key states.hpp
//  The Machine
//
//  Created by Indi Kernick on 9/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef player_key_states_hpp
#define player_key_states_hpp

#include <array>

struct PlayerKeyStates {
  std::array<bool, 4> dirs = {{}};
  bool action = false;
};

#endif
