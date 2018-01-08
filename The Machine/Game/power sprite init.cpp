//
//  power sprite init.cpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "power sprite init.hpp"

void PowerSpriteInit::init(PowerSprite &comp, const json &node) {
  Data::getOptional(comp.riseAndFall, node, "rise_and_fall");
  Data::getOptional(comp.off, node, "off");
  Data::getOptional(comp.on, node, "on");
  if (JSON_OPTIONAL(dir, node, "dir")) {
    comp.dir = static_cast<Math::Dir>(dir->get<Math::DirType>());
  }
}
