//
//  gate system.hpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef gate_system_hpp
#define gate_system_hpp

#include "entity grid.hpp"
#include <Simpleton/ECS/registry.hpp>

// read the inputs for a gate and calculate the output
void gateSystem(ECS::Registry &, const EntityGrid &);

#endif
