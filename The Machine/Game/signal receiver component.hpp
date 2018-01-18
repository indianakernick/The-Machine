//
//  signal receiver component.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef signal_receiver_component_hpp
#define signal_receiver_component_hpp

#include "signal channels.hpp"
#include <Simpleton/Data/json.hpp>

struct SignalReceiver {
  SignalChannel channel;
  
  static void init(SignalReceiver &comp, const json &node) {
    Data::get(comp.channel, node, "channel");
    if (comp.channel >= NUM_CHANNELS) {
      throw std::runtime_error("Signal channel out of range");
    }
  }
};

#endif
