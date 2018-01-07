//
//  anim sprite init.cpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "anim sprite init.hpp"

void AnimSpriteInit::init(AnimSprite &comp, const json &node) {
  Data::get(comp.sprite, node, "sprite");
  Data::get(comp.frames, node, "frames");
  Data::get(comp.depth, node, "depth");
}
