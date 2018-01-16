//
//  title screen writer.cpp
//  The Machine
//
//  Created by Indi Kernick on 15/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "title screen writer.hpp"

#include <Simpleton/SDL/paths.hpp>

TitleScreenWriter::TitleScreenWriter(const TextureID tex)
  : tex(tex),
    sheet(Unpack::makeSpritesheet(SDL::getResDir() + "title screen.atlas")) {}

void TitleScreenWriter::writeQuads(
  QuadIter quadIter,
  const Frame frame
) const {
  static const glm::vec2 CORNER[4] = {
    {0.0f, 0.0f}, {16.0f, 0.0f}, {16.0f, 9.0f}, {0.0f, 9.0f}
  };
  
  Quad &quad = *quadIter;
  for (size_t v = 0; v != 4; ++v) {
    quad[v].pos = glm::vec3(CORNER[v].x, CORNER[v].y, 0.0f);
  }
  
  writeTexCoords(quadIter, sheet, frame);
}

TextureID TitleScreenWriter::getTexture() const {
  return tex;
}

size_t TitleScreenWriter::count() const {
  return 1;
}
