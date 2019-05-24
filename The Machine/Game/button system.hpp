//
//  button system.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef button_system_hpp
#define button_system_hpp

#include "entity grid.hpp"
#include <entt/entity/registry.hpp>

// output power will the player is pressing the action button
void buttonSystem(entt::registry &, const EntityGrid &);

#endif
