//
//  transition writer.hpp
//  The Machine
//
//  Created by Indi Kernick on 19/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef transition_writer_hpp
#define transition_writer_hpp

#include <glm/vec3.hpp>
#include "quad writer.hpp"
#include "rendering helpers.hpp"

class TransitionWriter final : public QuadWriter {
public:
  TransitionWriter(TextureID, glm::vec3, Frame);
  
  void writeQuads(QuadIter, Frame) const override;
  TextureID getTexture() const override;
  glm::vec4 getColor(Frame) const override;
  size_t count() const override;

private:
  glm::vec3 color;
  TextureID tex;
  Frame duration;
};

#endif
