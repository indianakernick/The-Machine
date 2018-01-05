//
//  power input init.cpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "power input init.hpp"

void PowerInputInit::init(PowerInput &comp, const json &node) {
  comp.sides = static_cast<Math::DirBits>(node.at("sides").get<Math::DirType>());
}
