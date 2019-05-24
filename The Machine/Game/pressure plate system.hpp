//
//  pressure plate system.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef pressure_plate_system_hpp
#define pressure_plate_system_hpp

#include "entity grid.hpp"
#include <entt/entity/registry.hpp>

// outputs power if there is a dynamic entity in the same tile
void pressurePlateSystem(entt::registry &, const EntityGrid &);

#endif
