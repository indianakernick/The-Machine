//
//  title screen writer.cpp
//  The Machine
//
//  Created by Indi Kernick on 15/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "title screen writer.hpp"

void TitleScreenWriter::writeQuads(
  QuadIter quadIter,
  ECS::Registry &,
  const Spritesheet &sheet,
  const Frame frame
) const {
  static const glm::vec2 CORNER[4] = {
    {0.0f, 0.0f}, {1.0f, 0.0f}, {1.0f, 1.0f}, {0.0f, 1.0f}
  };
  
  Quad &quad = *quadIter;
  for (size_t v = 0; v != 4; ++v) {
    quad[v].pos = glm::vec3(CORNER[v].x, CORNER[v].y, 0.0f);
  }
  
  writeTexCoords(quadIter, sheet, frame);
}

size_t TitleScreenWriter::count(ECS::Registry &) const {
  return 1;
}
