//
//  transition writer.cpp
//  The Machine
//
//  Created by Indi Kernick on 19/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "transition writer.hpp"

#include <Simpleton/Math/interpolate.hpp>

TransitionWriter::TransitionWriter(
  const TextureID tex,
  const glm::vec3 color,
  const Frame duration
) : color(color),
    tex(tex),
    duration(duration) {}

void TransitionWriter::writeQuads(const QuadIter quadIter, Frame) const {
  Quad &quad = *quadIter;
  quad[0].pos = {-1.0f, -1.0f, 0.0f};
  quad[1].pos = {1.0f, -1.0f, 0.0f};
  quad[2].pos = {1.0f, 1.0f, 0.0f};
  quad[3].pos = {-1.0f, 1.0f, 0.0f};
  
  for (size_t v = 0; v != 4; ++v) {
    quad[v].texCoord = {0.5f, 0.5f};
  }
}

TextureID TransitionWriter::getTexture() const {
  return tex;
}

glm::vec4 TransitionWriter::getColor(const Frame frame) const {
  const float progress = 3.0f * static_cast<float>(frame) / duration;
  float alpha;
  if (progress <= 1.0f) {
    alpha = Math::sinOut(progress);
  } else if (progress <= 2.0f) {
    alpha = 1.0f;
  } else {
    alpha = Math::sinOut(3.0f - progress);
  }
  return {color.r, color.g, color.b, alpha};
}

size_t TransitionWriter::count() const {
  return 1;
}
