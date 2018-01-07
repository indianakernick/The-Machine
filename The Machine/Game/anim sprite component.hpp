//
//  anim sprite component.hpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef anim_sprite_component_hpp
#define anim_sprite_component_hpp

#include <unpacker.hpp>

struct AnimSprite {
  Unpack::SpriteID sprite;
  Unpack::SpriteID frames;
  float depth;
};

#endif
