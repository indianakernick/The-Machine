//
//  move dir system.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef move_dir_system_hpp
#define move_dir_system_hpp

#include "entity grid.hpp"
#include <entt/entity/registry.hpp>

// calculate Movement::realDir from Movement::desiredDir and collisions
void moveDirSystem(entt::registry &, const EntityGrid &);

#endif
