//
//  rendering helpers.cpp
//  The Machine
//
//  Created by Indi Kernick on 16/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "rendering helpers.hpp"

void writePos(
  const QuadIter quadIter,
  const SpritePosition spritePos
) {
  static const glm::vec2 CORNER[4] = {
    {0.0f, 0.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 1.0f}
  };
  const size_t dirI = static_cast<size_t>(spritePos.orient);
  
  Quad &quad = *quadIter;
  for (size_t v = 0; v != 4; ++v) {
    //winding is anticlockwise
    //dir increases clockwise
    const glm::vec2 vert = spritePos.pos + CORNER[(4 + v - dirI) % 4];
    quad[v].pos = glm::vec3(vert.x, vert.y, spritePos.depth);
  }
}

void writeTexCoords(
  const QuadIter quadIter,
  const Spritesheet &sheet,
  const SpriteID sprite
) {
  const Unpack::Rect rect = sheet.getSprite(sprite);
  
  Quad &quad = *quadIter;
  quad[0].texCoord = rect.min;
  quad[1].texCoord = {rect.max.x, rect.min.y};
  quad[2].texCoord = rect.max;
  quad[3].texCoord = {rect.min.x, rect.max.y};
}
