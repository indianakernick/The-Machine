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

struct Anim {
  Unpack::SpriteID start;
  int dir;
};

struct PowerSprite {
  Anim low;
  Anim rise;
  Anim fall;
  Anim high;
};

#endif
