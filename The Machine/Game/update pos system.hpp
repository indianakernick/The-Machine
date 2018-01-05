//
//  update pos system.hpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef update_pos_system_hpp
#define update_pos_system_hpp

#include "entity grid.hpp"
#include <Simpleton/ECS/registry.hpp>

// update Position::pos and EntityGrid according to Movement::realDir
void updatePosSystem(ECS::Registry &, EntityGrid &);

#endif
