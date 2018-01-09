//
//  player input system.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef player_input_system_hpp
#define player_input_system_hpp

#include "player key states.hpp"

extern "C" union SDL_Event;

void playerInputSystem(PlayerKeyStates &, const SDL_Event &);

#endif
