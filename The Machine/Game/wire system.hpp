//
//  wire system.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef wire_system_hpp
#define wire_system_hpp

#include "entity grid.hpp"
#include <entt/entity/registry.hpp>

// propagate power from PowerOutputs to PowerInputs through Wires
void wireSystem(entt::registry &, const EntityGrid &);

#endif
