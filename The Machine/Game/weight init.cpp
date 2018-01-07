//
//  weight init.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "weight init.hpp"

void WeightInit::init(Weight &comp, const json &node) {
  Data::get(comp.heavy, node, "heavy");
}
