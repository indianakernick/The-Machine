//
//  radioactivity sprite writer.cpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "radioactivity sprite writer.hpp"

#include "radioactivity component.hpp"
#include "radioactivity sprite component.hpp"

RadioactivitySpriteWriter::RadioactivitySpriteWriter(
  const TextureID tex,
  std::shared_ptr<entt::registry> registry,
  std::shared_ptr<Sheet> sheet
) : tex(tex),
    registry(registry),
    sheet(sheet) {}

void RadioactivitySpriteWriter::writeQuads(QuadIter quadIter, const Frame frame) const {
  const auto view = registry->view<Radioactivity, RadioactivitySprite, SpritePosition>();
  for (const entt::entity entity : view) {
    const Radioactivity activity = view.get<Radioactivity>(entity);
    const RadioactivitySprite sprite = view.get<RadioactivitySprite>(entity);
    const bool animate = activity.curr != activity.prev;
    
    Sprite::ID animFrame = sprite.sprite;
    if (activity.prev) {
      animFrame += FRAMES_PER_TICK;
      if (animate) {
        animFrame -= frame; // falling anim
      }
    } else if (animate) {
      animFrame += frame; // rising anim
    }
    
    writePos(quadIter, view.get<SpritePosition>(entity));
    writeTexCoords(quadIter, *sheet, animFrame);
    
    ++quadIter;
  }
}

TextureID RadioactivitySpriteWriter::getTexture() const {
  return tex;
}

size_t RadioactivitySpriteWriter::count() const {
  return registry->view<RadioactivitySprite>().size();
}
