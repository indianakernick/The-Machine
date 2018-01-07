//
//  channel sprite component.hpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef channel_sprite_component_hpp
#define channel_sprite_component_hpp

#include <unpacker.hpp>

struct ChannelSprite {
  Unpack::SpriteID sprite;
  float depth;
};

#endif
