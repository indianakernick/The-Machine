//
//  radioactivity sprite component.hpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef radioactivity_sprite_component_hpp
#define radioactivity_sprite_component_hpp

#include <unpacker.hpp>

struct RadioactivitySprite {
  Unpack::SpriteID sprite;
  float depth;
};

#endif
