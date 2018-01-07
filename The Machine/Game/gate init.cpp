//
//  gate init.cpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "gate init.hpp"

void GateInit::init(Gate &comp, const json &node) {
  comp.fun = static_cast<GateFun>(node.at("fun").get<int>());
}
