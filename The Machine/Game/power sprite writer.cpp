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

PowerSpriteWriter::PowerSpriteWriter(
  const TextureID tex,
  std::shared_ptr<entt::registry> registry,
  std::shared_ptr<Sheet> sheet
) : tex(tex),
    registry(registry),
    sheet(sheet) {}

void PowerSpriteWriter::writeQuads(QuadIter quadIter, const Frame frame) const {
  const auto view = registry->view<Power, PowerSprite, SpritePosition>();
  for (const entt::entity entity : view) {
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
    
    const Sprite::ID animFrame = anim.start + anim.dir * frame;
    
    writePos(quadIter, view.get<SpritePosition>(entity));
    writeTexCoords(quadIter, *sheet, animFrame);
    
    ++quadIter;
  }
}

TextureID PowerSpriteWriter::getTexture() const {
  return tex;
}

size_t PowerSpriteWriter::count() const {
  return registry->view<PowerSprite>().size();
}
