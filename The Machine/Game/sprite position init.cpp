//
//  sprite position init.cpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "sprite position init.hpp"

void SpritePositionInit::init(SpritePosition &comp, const json &node) {
  Data::get(comp.depth, node, "depth");
  if (JSON_OPTIONAL(orient, node, "dir")) {
    comp.orient = static_cast<Math::Dir>(orient->get<Math::DirType>());
  }
}
