//
//  anim sprite writer.cpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "anim sprite writer.hpp"

#include "position component.hpp"
#include "anim sprite component.hpp"

void QuadWriter::writeQuads(
  QuadIter quadIter,
  ECS::Registry &registry,
  const Spritesheet &sheet,
  const Frame frame
) const {
  const auto view = registry.view<Position, AnimSprite>();
  for (const ECS::EntityID entity : view) {
    const Pos pos = view.get<Position>(entity).pos;
    const AnimSprite sprite = view.get<AnimSprite>(entity);
    const Unpack::SpriteID animFrame =
      std::min(sprite.sprite + frame, sprite.frames - 1);
    
    writePos(quadIter, pos, sprite.depth);
    writeTexCoords(quadIter, sheet, animFrame);
  }
}

size_t QuadWriter::count(ECS::Registry &registry) const {
  return registry.view<AnimSprite>().size();
}
