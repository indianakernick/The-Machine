//
//  signal channel component.hpp
//  The Machine
//
//  Created by Indi Kernick on 18/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef signal_channel_component_hpp
#define signal_channel_component_hpp

#include <cstdint>
#include <Simpleton/Data/json.hpp>

struct SignalChannel {
  uint8_t channel;
  
  static constexpr uint8_t NUM_CHANNELS = 8;
  
  static void init(SignalChannel &comp, const json &node) {
    Data::get(comp.channel, node, "channel");
  }
};

#endif
