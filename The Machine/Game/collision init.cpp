//
//  collision init.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "collision init.hpp"

void CollisionInit::init(Collision &comp, const json &node) {
  comp.typeBit = node.at("type").get<uint32_t>();
  comp.pushedBy = node.at("pushed_by").get<uint32_t>();
  comp.accepts = node.at("accepts").get<uint32_t>();
}
