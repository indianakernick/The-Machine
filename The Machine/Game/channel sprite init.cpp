//
//  channel sprite init.cpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "channel sprite init.hpp"

void ChannelSpriteInit::init(ChannelSprite &comp, const json &node) {
  Data::get(comp.sprite, node, "sprite");
  Data::get(comp.depth, node, "depth");
}
