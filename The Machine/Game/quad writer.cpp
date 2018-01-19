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

size_t QuadWriter::countQuads() {
  return quadCount = count();
}

glm::vec4 QuadWriter::getColor(Frame) const {
  return {1.0f, 1.0f, 1.0f, 1.0f};
}
