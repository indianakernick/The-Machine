//
//  exit system.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef exit_system_hpp
#define exit_system_hpp

#include "entity grid.hpp"
#include <entt/entity/registry.hpp>

// return true if the player is in the exit tile
bool exitSystem(entt::registry &, const EntityGrid &);

#endif
