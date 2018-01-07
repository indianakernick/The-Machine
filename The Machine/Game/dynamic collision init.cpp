//
//  dynamic collision init.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "dynamic collision init.hpp"

void DynamicCollisionInit::init(DynamicCollision &comp, const json &node) {
  Data::get(comp.type, node, "type");
  Data::get(comp.pushedBy, node, "pushed_by");
}
