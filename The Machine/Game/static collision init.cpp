//
//  static collision init.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "static collision init.hpp"

void StaticCollisionInit::init(StaticCollision &comp, const json &node) {
  comp.type = node.at("type").get<uint32_t>();
  comp.accepts = node.at("accepts").get<uint32_t>();
}
