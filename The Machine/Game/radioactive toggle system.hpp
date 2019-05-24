//
//  radioactive toggle system.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef radioactive_toggle_system_hpp
#define radioactive_toggle_system_hpp

#include "entity grid.hpp"
#include <entt/entity/registry.hpp>

// toggle the radioactivity of the dynamic entity in front on the falling edge
// of power
void radioactiveToggleSystem(entt::registry &, const EntityGrid &);

#endif
