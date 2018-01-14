//
//  static sprite writer.cpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "static sprite writer.hpp"

#include "static sprite component.hpp"

void StaticSpriteWriter::writeQuads(
  QuadIter quadIter,
  ECS::Registry &registry,
  const Spritesheet &sheet,
  Frame
) const {
  auto view = registry.view<StaticSprite, SpritePosition>();
  for (const ECS::EntityID entity : view) {
    StaticSprite &sprite = view.get<StaticSprite>(entity);
    const Unpack::SpriteID spriteID = sprite.sprite + sprite.frame;
    /*
    Running at 60 fps
    using Frame = uint32_t
    
    sprite.repeats overflows in
    2 years 98 days 12 hours 6 minutes 28 seconds 16 frames
    */
    ++sprite.repeats;
    if (sprite.repeats == sprite.ticks && sprite.ticks != 0) {
      sprite.repeats = 0;
      ++sprite.frame;
      if (sprite.frame == FRAMES_PER_TICK) {
        sprite.frame = 0;
      }
    }
    
    writePos(quadIter, view.get<SpritePosition>(entity));
    writeTexCoords(quadIter, sheet, spriteID);
    
    ++quadIter;
  }
}

size_t StaticSpriteWriter::count(ECS::Registry &registry) const {
  return registry.view<StaticSprite>().size();
}
