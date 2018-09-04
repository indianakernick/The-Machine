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
#include "signal channel component.hpp"

namespace {
  void setChannel0(PowerSprite &sprite) {
    constexpr Sprite::ID idChange = (SignalChannel::NUM_CHANNELS - 1) * FRAMES_PER_TICK;
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
  auto view = registry.view<PowerSprite, SignalChannel, Position>();
  for (const ECS::EntityID entity : view) {
    const Pos pos = view.get<Position>(entity).pos;
    const ECS::EntityID targetID = grid[pos].dynamicID;
    
    if (targetID == entt::null) {
      continue;
    }
    
    if (!registry.has<PlayerAction>(targetID)) {
      continue;
    }
    
    const PlayerAction action = registry.get<PlayerAction>(targetID);
    if (!action.prev && action.curr) {
      PowerSprite &sprite = view.get<PowerSprite>(entity);
      auto &channel = view.get<SignalChannel>(entity).channel;
      if (channel == SignalChannel::NUM_CHANNELS - 1) {
        setChannel0(sprite);
        channel = 0;
      } else {
        incrChannel(sprite);
        ++channel;
      }
    }
  }
}
