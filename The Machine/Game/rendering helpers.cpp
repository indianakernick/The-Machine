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
  const Unpack::VecPx unpackSheetSize = sheet.getSize();
  const glm::vec2 sheetSize = {unpackSheetSize.x, unpackSheetSize.y};
  const Unpack::RectPx rect = sheet.getSprite(sprite);
  glm::vec2 bottomLeft = glm::vec2(rect.x, rect.y) / sheetSize;
  glm::vec2 topRight = bottomLeft + glm::vec2(rect.w, rect.h) / sheetSize;
  
  Quad &quad = *quadIter;
  quad[0].texCoord = {bottomLeft.x, topRight.y};
  quad[1].texCoord = topRight;
  quad[2].texCoord = {topRight.x, bottomLeft.y};
  quad[3].texCoord = bottomLeft;
}
