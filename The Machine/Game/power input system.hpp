//
//  power input system.hpp
//  The Machine
//
//  Created by Indi Kernick on 10/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef power_input_system_hpp
#define power_input_system_hpp

#include "entity grid.hpp"
#include <Simpleton/ECS/registry.hpp>

void powerInputSystem(ECS::Registry &, const EntityGrid &);

#endif
