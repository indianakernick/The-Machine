//
//  quad writer.cpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "quad writer.hpp"

#include <glm/mat2x2.hpp>

size_t QuadWriter::numQuads() const {
  return quadCount;
}

size_t QuadWriter::countQuads(ECS::Registry &registry) {
  return quadCount = count(registry);
}

void QuadWriter::writePos(
  const QuadIter quadIter,
  const Pos pos,
  const float depth
) {
  static const Pos CORNER[4] = {
    {0, 0}, {1, 0}, {1, 1}, {0, 1}
  };
  Quad &quad = *quadIter;
  for (size_t v = 0; v != 4; ++v) {
    const glm::vec2 vert = pos + CORNER[v];
    quad[v].pos = glm::vec3(vert.x, vert.y, depth);
  }
}

void QuadWriter::writeTexCoords(
  const QuadIter quadIter,
  const Spritesheet &sheet,
  const SpriteID sprite,
  const float angle
) {
  const Unpack::VecPx unpackSheetSize = sheet.getSize();
  const glm::vec2 sheetSize = {unpackSheetSize.x, unpackSheetSize.y};
  const Unpack::RectPx rect = sheet.getSprite(sprite);
  glm::vec2 bottomLeft = glm::vec2(rect.x, rect.y) / sheetSize;
  glm::vec2 topRight = bottomLeft + glm::vec2(rect.w, rect.h) / sheetSize;
  
  const float s = std::sin(angle);
  const float c = std::cos(angle);
  const glm::mat2 rotation = {{c, s}, {-s, c}};
  
  bottomLeft = rotation * bottomLeft;
  topRight = rotation * topRight;
  
  Quad &quad = *quadIter;
  quad[0].texCoord = {bottomLeft.x, topRight.y};
  quad[1].texCoord = topRight;
  quad[2].texCoord = {topRight.x, bottomLeft.y};
  quad[3].texCoord = bottomLeft;
}
