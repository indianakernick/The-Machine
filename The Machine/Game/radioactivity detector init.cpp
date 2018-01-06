//
//  radioactivity detector init.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "radioactivity detector init.hpp"

void RadioactivityDetectorInit::init(RadioactivityDetector &comp, const json &node) {
  comp.side = static_cast<Math::Dir>(node.at("side").get<Math::DirType>());
}
