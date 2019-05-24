//
//  init grid system.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef init_grid_system_hpp
#define init_grid_system_hpp

#include "entity grid.hpp"
#include <entt/entity/registry.hpp>

// Put all of the entities in to the grid
void initGridSystem(entt::registry &, EntityGrid &);

#endif
