//
//  signal channel toggle system.cpp
//  The Machine
//
//  Created by Indi Kernick on 17/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "signal channel toggle system.hpp"

#include "frame type.hpp"
#include "position component.hpp"
#include "power sprite component.hpp"
#include "player action component.hpp"
#include "signal receiver component.hpp"
#include "signal transmitter component.hpp"

namespace {
  void setChannel0(PowerSprite &sprite) {
    const Unpack::SpriteID idChange = (NUM_CHANNELS - 1) * FRAMES_PER_TICK;
    sprite.low.start -= idChange;
    sprite.rise.start -= idChange;
    sprite.fall.start -= idChange;
    sprite.high.start -= idChange;
  }
  
  void incrChannel(PowerSprite &sprite) {
    sprite.low.start += FRAMES_PER_TICK;
    sprite.rise.start += FRAMES_PER_TICK;
    sprite.fall.start += FRAMES_PER_TICK;
    sprite.high.start += FRAMES_PER_TICK;
  }
}

void signalChannelToggleSystem(ECS::Registry &registry, const EntityGrid &grid) {
  // @TODO maybe create a SignalChannel component?
  
  auto rView = registry.view<PowerSprite, SignalReceiver, Position>();
  for (const ECS::EntityID entity : rView) {
    const Pos pos = rView.get<Position>(entity).pos;
    const ECS::EntityID targetID = grid[pos].dynamicID;
    
    if (targetID == ECS::NULL_ENTITY) {
      continue;
    }
    
    if (!registry.has<PlayerAction>(targetID)) {
      continue;
    }
    
    const PlayerAction action = registry.get<PlayerAction>(targetID);
    if (!action.prev && action.curr) {
      PowerSprite &sprite = rView.get<PowerSprite>(entity);
      SignalReceiver &receiver = rView.get<SignalReceiver>(entity);
      if (receiver.channel == NUM_CHANNELS - 1) {
        setChannel0(sprite);
        receiver.channel = 0;
      } else {
        incrChannel(sprite);
        ++receiver.channel;
      }
    }
  }
  
  auto tView = registry.view<PowerSprite, SignalTransmitter, Position>();
  for (const ECS::EntityID entity : tView) {
    const Pos pos = tView.get<Position>(entity).pos;
    const ECS::EntityID targetID = grid[pos].dynamicID;
    
    if (targetID == ECS::NULL_ENTITY) {
      continue;
    }
    
    if (!registry.has<PlayerAction>(targetID)) {
      continue;
    }
    
    const PlayerAction action = registry.get<PlayerAction>(targetID);
    if (!action.prev && action.curr) {
      PowerSprite &sprite = tView.get<PowerSprite>(entity);
      SignalTransmitter &transmitter = tView.get<SignalTransmitter>(entity);
      if (transmitter.channel == NUM_CHANNELS - 1) {
        setChannel0(sprite);
        transmitter.channel = 0;
      } else {
        incrChannel(sprite);
        ++transmitter.channel;
      }
    }
  }
}
