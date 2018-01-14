//
//  power sprite init.cpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "power sprite init.hpp"

static void from_json(const json &node, Anim &anim) {
  Data::get(anim.start, node, "start");
  Data::get(anim.dir, node, "dir");
}

void PowerSpriteInit::init(PowerSprite &comp, const json &node) {
  Data::get(comp.low, node, "low");
  Data::get(comp.rise, node, "rise");
  Data::get(comp.fall, node, "fall");
  Data::get(comp.high, node, "high");
}
