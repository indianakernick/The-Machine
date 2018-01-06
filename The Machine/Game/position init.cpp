//
//  position init.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "position init.hpp"

void PositionInit::init(Position &comp, const json &node) {
  comp.pos = node.get<Pos>();
}
