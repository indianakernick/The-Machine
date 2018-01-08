//
//  static sprite init.cpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "static sprite init.hpp"

void StaticSpriteInit::init(StaticSprite &comp, const json &node) {
  Data::get(comp.sprite, node, "sprite");
  Data::get(comp.depth, node, "depth");
  Data::get(comp.animated, node, "animated");
}
