//
//  sprite position system.hpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef sprite_position_system_hpp
#define sprite_position_system_hpp

#include "frame type.hpp"
#include <entt/entity/registry.hpp>

// set SpritePosition based on the Movement of the entity
void spritePositionSystem(entt::registry &, Frame);

#endif
