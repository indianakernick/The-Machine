//
//  power sprite component.hpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef power_sprite_component_hpp
#define power_sprite_component_hpp

#include <unpacker.hpp>

struct PowerSprite {
  Unpack::SpriteID riseAndFall = Unpack::NULL_SPRITE;
  Unpack::SpriteID off = Unpack::NULL_SPRITE;
  Unpack::SpriteID on = Unpack::NULL_SPRITE;
};

#endif
