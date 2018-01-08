//
//  radioactivity sprite init.cpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "radioactivity sprite init.hpp"

void RadioactivitySpriteInit::init(RadioactivitySprite &comp, const json &node) {
  Data::get(comp.sprite, node, "sprite");
}
