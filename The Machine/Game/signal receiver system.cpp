//
//  signal receiver system.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "signal receiver system.hpp"

#include "power component.hpp"
#include "signal channel component.hpp"
#include "signal receiver component.hpp"
#include "signal transmitter component.hpp"

void signalReceiverSystem(entt::registry &registry) {
  const auto transmitters = registry.view<Power, SignalChannel, SignalTransmitter>();
  auto receivers = registry.view<Power, SignalChannel, SignalReceiver>();
  bool channelStates[SignalChannel::NUM_CHANNELS] = {};
  
  for (const entt::entity entity : transmitters) {
    const auto channel = transmitters.get<SignalChannel>(entity).channel;
    const bool state = transmitters.get<Power>(entity).prev;
    channelStates[channel] = channelStates[channel] || state;
  }
  
  for (const entt::entity entity : receivers) {
    const auto channel = receivers.get<SignalChannel>(entity).channel;
    receivers.get<Power>(entity).curr = channelStates[channel];
  }
}
