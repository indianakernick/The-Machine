//
//  piston system.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef piston_system_hpp
#define piston_system_hpp

#include "entity grid.hpp"
#include <entt/entity/registry.hpp>

// move a piston head if the piston base is being powered
void pistonSystem(entt::registry &, const EntityGrid &);

#endif
