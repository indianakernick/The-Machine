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
#include <Simpleton/Math/dir.hpp>

struct StaticSprite {
  Unpack::SpriteID sprite;
  float depth;
  bool animated;
  Math::Dir dir = Math::Dir::UP;
};

#endif
