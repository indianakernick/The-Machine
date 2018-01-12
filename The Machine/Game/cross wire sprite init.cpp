//
//  cross wire sprite init.cpp
//  The Machine
//
//  Created by Indi Kernick on 10/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "cross wire sprite init.hpp"

void CrossWireSpriteInit::init(CrossWireSprite &comp, const json &node) {
  Data::get(comp.both, node, "both");
  Data::get(comp.inverted, node, "inverted");
  Data::get(comp.horiOff, node, "hori_off");
  Data::get(comp.horiOn, node, "hori_on");
}
