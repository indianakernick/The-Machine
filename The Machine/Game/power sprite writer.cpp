//
//  power sprite writer.cpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "power sprite writer.hpp"

#include "power component.hpp"
#include "power sprite component.hpp"

void PowerSpriteWriter::writeQuads(
  QuadIter quadIter,
  ECS::Registry &registry,
  const Spritesheet &sheet,
  const Frame frame
) const {
  const auto view = registry.view<Power, PowerSprite, SpritePosition>();
  for (const ECS::EntityID entity : view) {
    const Power power = view.get<Power>(entity);
    const PowerSprite sprite = view.get<PowerSprite>(entity);
    const bool transition = power.curr != power.prev;
    
    Unpack::SpriteID animFrame;
    if (transition) {
      animFrame = sprite.transition;
      if (power.prev) {
        animFrame += FRAMES_PER_TICK;
      }
      animFrame -= frame;
    } else if (power.prev) {
      if (sprite.on != Unpack::NULL_SPRITE) {
        animFrame = sprite.on + frame;
      } else {
        animFrame = sprite.transition + FRAMES_PER_TICK;
      }
    } else {
      if (sprite.off != Unpack::NULL_SPRITE) {
        animFrame = sprite.off + frame;
      } else {
        animFrame = sprite.transition;
      }
    }
    
    writePos(quadIter, view.get<SpritePosition>(entity));
    writeTexCoords(quadIter, sheet, animFrame);
    
    ++quadIter;
  }
}

size_t PowerSpriteWriter::count(ECS::Registry &registry) const {
  return registry.view<PowerSprite>().size();
}
