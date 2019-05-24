//
//  lever system.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef lever_system_hpp
#define lever_system_hpp

#include "entity grid.hpp"
#include <entt/entity/registry.hpp>

// toggle power output if the player presses the action button
void leverSystem(entt::registry &, const EntityGrid &);

#endif
