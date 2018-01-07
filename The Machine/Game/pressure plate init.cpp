//
//  pressure plate init.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "pressure plate init.hpp"

void PressurePlateInit::init(PressurePlate &comp, const json &node) {
  Data::get(comp.heavy, node, "heavy");
}
