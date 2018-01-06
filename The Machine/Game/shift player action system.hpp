//
//  shift player action system.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef shift_player_action_system_hpp
#define shift_player_action_system_hpp

#include <Simpleton/ECS/registry.hpp>

// set PlayerAction::prev to PlayerAction::curr
void shiftPlayerActionSystem(ECS::Registry &);

#endif
