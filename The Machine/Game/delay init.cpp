//
//  delay init.cpp
//  The Machine
//
//  Created by Indi Kernick on 13/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "delay init.hpp"

void DelayInit::init(Delay &comp, const json &node) {
  Data::get(comp.length, node, "length");
}
