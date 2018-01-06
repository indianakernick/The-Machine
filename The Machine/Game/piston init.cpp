//
//  piston init.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "piston init.hpp"

void PistonInit::init(Piston &comp, const json &node) {
  comp.dir = static_cast<Math::Dir>(node.at("dir").get<Math::DirType>());
}
