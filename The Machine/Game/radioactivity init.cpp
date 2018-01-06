//
//  radioactivity init.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "radioactivity init.hpp"

void RadioactivityInit::init(Radioactivity &comp, const json &node) {
  Data::getOptional(comp.curr, node, "enabled");
}
