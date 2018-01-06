//
//  weight init.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "weight init.hpp"

void WeightInit::init(Weight &weight, const json &node) {
  weight.heavy = node.at("heavy").get<bool>();
}
