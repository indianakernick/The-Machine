//
//  signal receiver init.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "signal receiver init.hpp"

void SignalReceiverInit::init(SignalReceiver &comp, const json &node) {
  Data::get(comp.channel, node, "channel");
  if (comp.channel >= NUM_CHANNELS) {
    throw std::runtime_error("Signal channel out of range");
  }
}
