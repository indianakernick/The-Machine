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
#include <Simpleton/Data/json.hpp>

struct CrossWireSprite {
  Unpack::SpriteID both;
  Unpack::SpriteID inverted;
  Unpack::SpriteID horiOff;
  Unpack::SpriteID horiOn;
  
  static void init(CrossWireSprite &comp, const json &node) {
    Data::get(comp.both, node, "both");
    Data::get(comp.inverted, node, "inverted");
    Data::get(comp.horiOff, node, "hori_off");
    Data::get(comp.horiOn, node, "hori_on");
  }
};

#endif
