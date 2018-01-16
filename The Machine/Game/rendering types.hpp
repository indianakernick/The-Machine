//
//  rendering types.hpp
//  The Machine
//
//  Created by Indi Kernick on 22/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef rendering_types_hpp
#define rendering_types_hpp

#include <array>
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

using PosType = glm::vec3;
using TexCoordType = glm::vec2;
using ElemType = unsigned short;

struct Vertex {
  PosType pos;
  TexCoordType texCoord;
};
using Quad = std::array<Vertex, 4>;

using Quads = std::vector<Quad>;
using QuadIter = typename Quads::iterator;
using Elems = std::vector<ElemType>;
using TextureID = size_t;

#endif
