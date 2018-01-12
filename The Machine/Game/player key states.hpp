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

struct KeyState {
  bool downLastTick = false;  // the key was pressed last tick
  bool down = false;          // the key is being held down
};

struct PlayerKeyStates {
  std::array<KeyState, 4> dirs = {};
  KeyState action;
};

#endif
