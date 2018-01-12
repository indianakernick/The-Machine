//
//  clear player input system.cpp
//  The Machine
//
//  Created by Indi Kernick on 9/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "clear player input system.hpp"

void clearPlayerInputSystem(PlayerKeyStates &events) {
  for (KeyState &state : events.dirs) {
    state.downLastTick = false;
  }
  events.action.downLastTick = false;
}
