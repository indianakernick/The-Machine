//
//  cross wire sprite component.hpp
//  The Machine
//
//  Created by Indi Kernick on 10/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef cross_wire_sprite_component_hpp
#define cross_wire_sprite_component_hpp

#include <unpacker.hpp>

struct CrossWireSprite {
  Unpack::SpriteID both;
  Unpack::SpriteID inverted;
  Unpack::SpriteID horiOff;
  Unpack::SpriteID horiOn;
};

#endif
