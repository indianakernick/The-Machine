//
//  power input system.hpp
//  The Machine
//
//  Created by Indi Kernick on 13/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef power_input_system_hpp
#define power_input_system_hpp

#include "entity grid.hpp"
#include <entt/entity/registry.hpp>

// read power state from input sides and set input state
void powerInputSystem(entt::registry &, const EntityGrid &);

#endif
