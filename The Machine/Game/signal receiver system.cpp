//
//  signal receiver system.cpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "signal receiver system.hpp"

#include "power component.hpp"
#include "signal receiver component.hpp"
#include "signal transmitter component.hpp"

void signalReceiverSystem(ECS::Registry &registry) {
  const auto transmitters = registry.view<Power, SignalTransmitter>();
  auto receivers = registry.view<Power, SignalReceiver>();
  bool channelStates[NUM_CHANNELS] = {};
  
  for (const ECS::EntityID entity : transmitters) {
    const SignalChannel channel = transmitters.get<SignalTransmitter>(entity).channel;
    const bool state = transmitters.get<Power>(entity).prev;
    channelStates[channel] = channelStates[channel] || state;
  }
  
  for (const ECS::EntityID entity : receivers) {
    const SignalChannel channel = receivers.get<SignalReceiver>(entity).channel;
    receivers.get<Power>(entity).curr = channelStates[channel];
  }
}
