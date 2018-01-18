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
#include <Simpleton/Data/json.hpp>

struct Anim {
  Unpack::SpriteID start;
  int dir;
};

inline void from_json(const json &node, Anim &anim) {
  Data::get(anim.start, node, "start");
  Data::get(anim.dir, node, "dir");
}

struct PowerSprite {
  Anim low;
  Anim rise;
  Anim fall;
  Anim high;
  
  static void init(PowerSprite &comp, const json &node) {
    Data::get(comp.low, node, "low");
    Data::get(comp.rise, node, "rise");
    Data::get(comp.fall, node, "fall");
    Data::get(comp.high, node, "high");
  }
};

#endif
