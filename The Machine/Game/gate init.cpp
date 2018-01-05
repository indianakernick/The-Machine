//
//  gate init.cpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "gate init.hpp"

void GateInit::init(Gate &gate, const json &node) {
  gate.fun = static_cast<GateFun>(node.at("fun").get<int>());
}
