//
//  signal transmitter init.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "signal transmitter init.hpp"

void SignalTransmitterInit::init(SignalTransmitter &comp, const json &node) {
  comp.channel = node.at("channel").get<uint8_t>();
}
