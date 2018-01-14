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
    
    Anim anim;
    if (!power.prev && !power.curr) {
      anim = sprite.low;
    } else if (!power.prev && power.curr) {
      anim = sprite.rise;
    } else if (power.prev && !power.curr) {
      anim = sprite.fall;
    } else {
      anim = sprite.high;
    }
    
    const Unpack::SpriteID animFrame = anim.start + anim.dir * frame;
    
    writePos(quadIter, view.get<SpritePosition>(entity));
    writeTexCoords(quadIter, sheet, animFrame);
    
    ++quadIter;
  }
}

size_t PowerSpriteWriter::count(ECS::Registry &registry) const {
  return registry.view<PowerSprite>().size();
}
