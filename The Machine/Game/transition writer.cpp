//
//  transition writer.cpp
//  The Machine
//
//  Created by Indi Kernick on 19/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "transition writer.hpp"

TransitionWriter::TransitionWriter(
  const TextureID tex,
  const glm::vec2 whitepx,
  const Frame duration
) : tex(tex),
    whitepx(whitepx),
    duration(duration) {}

void TransitionWriter::writeQuads(const QuadIter quadIter, Frame) const {
  Quad &quad = *quadIter;
  quad[0].pos = {0.0f, 0.0f, 0.0f};
  quad[1].pos = {16.0f, 0.0f, 0.0f};
  quad[2].pos = {16.0f, 9.0f, 0.0f};
  quad[3].pos = {0.0f, 9.0f, 0.0f};
  
  for (size_t v = 0; v != 4; ++v) {
    quad[v].texCoord = whitepx;
  }
}

TextureID TransitionWriter::getTexture() const {
  return tex;
}

glm::vec4 TransitionWriter::getColor(const Frame frame) const {
  const float progress = static_cast<float>(frame) / duration;
  float alpha;
  if (progress <= 0.5f) {
    alpha = progress * 2.0f;
  } else {
    alpha = progress * -2.0f + 2.0f;
  }
  return {0.0f, 0.0f, 0.0f, alpha};
}

size_t TransitionWriter::count() const {
  return 1;
}
