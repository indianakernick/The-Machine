//
//  player input response system.hpp
//  The Machine
//
//  Created by Indi Kernick on 9/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef player_input_response_system_hpp
#define player_input_response_system_hpp

#include "player key states.hpp"
#include <Simpleton/ECS/registry.hpp>

void playerInputResponseSystem(ECS::Registry &, PlayerKeyStates);

#endif
