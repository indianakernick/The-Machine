//
//  static sprite component.hpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef static_sprite_component_hpp
#define static_sprite_component_hpp

#include <unpacker.hpp>

struct StaticSprite {
  Unpack::SpriteID sprite;
  bool animated;
};

#endif
