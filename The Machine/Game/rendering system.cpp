//
//  rendering system.cpp
//  The Machine
//
//  Created by Indi Kernick on 19/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "rendering system.hpp"

#include <fstream>
#include <Simpleton/SDL/paths.hpp>
#include <Simpleton/Utils/profiler.hpp>
#include <Simpleton/OpenGL/uniforms.hpp>
#include <Simpleton/OpenGL/attrib pointer.hpp>
#include <Simpleton/Graphics 2D/load surface.hpp>

namespace {
  ///Number of indicies that make up a quad
  constexpr size_t QUAD_INDICIES = 6;
  ///Number of verticies that make up a quad
  constexpr size_t QUAD_VERTS = 4;
  ///Byte size of a quad in a GL_ARRAY_BUFFER
  constexpr size_t QUAD_ATTR_SIZE = (sizeof(PosType) + sizeof(TexCoordType)) * QUAD_VERTS;
  ///Byte size of a quad in a GL_ELEMENT_ARRAY_BUFFER
  constexpr size_t QUAD_ELEM_SIZE = sizeof(ElemType) * QUAD_INDICIES;
  
  using Attribs = std::tuple<PosType, TexCoordType>;
  
  const char VERT_SHADER[] = R"delimiter(
#version 410 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 texCoord;

out vec2 fragTexCoord;

uniform mat3 viewProj;

void main() {
  gl_Position.xy = (viewProj * vec3(pos.xy, 1.0)).xy;
  gl_Position.zw = vec2(pos.z, 1.0);
  fragTexCoord = texCoord;
}
)delimiter";

  const char FRAG_SHADER[] = R"delimiter(
#version 410 core

in vec2 fragTexCoord;

uniform sampler2D tex;
uniform vec4 color;

out vec4 outColor;

void main() {
  outColor = color * texture(tex, fragTexCoord);
  gl_FragDepth = (outColor.a == 0.0 ? 1.0 : gl_FragCoord.z);
}
)delimiter";
}

void RenderingSystem::init() {
  PROFILE(RenderingSystem::init);

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  vertArray = GL::makeVertexArray();
  
  program = GL::makeShaderProgram(
    GL::makeVertShader(VERT_SHADER, sizeof(VERT_SHADER)),
    GL::makeFragShader(FRAG_SHADER, sizeof(FRAG_SHADER))
  );
  
  viewProjLoc = program.getUniformLoc("viewProj");
  texLoc = program.getUniformLoc("tex");
  colorLoc = program.getUniformLoc("color");
  
  program.use();
  GL::setUniform(texLoc, 0);
  GL::unuseProgram();
}

void RenderingSystem::quit() {
  elemBuf.reset();
  arrayBuf.reset();
  vertArray.reset();
  textures.clear();
}

QuadWriter &RenderingSystem::getWriter(const WriterID id) const {
  return *writers.at(id);
}

TextureID RenderingSystem::addTexture(const std::string_view name) {
  const G2D::Surface image = G2D::loadSurfaceRGBA(SDL::getResDir() + std::string(name));
  const GL::Image2D glImage = {
    image.data(),
    static_cast<GLsizei>(image.width()),
    static_cast<GLsizei>(image.height())
  };
  GL::TexParams2D texParams;
  texParams.setWrap(GL_CLAMP_TO_EDGE);
  texParams.setFilter(GL_NEAREST);
  return addTexture(GL::makeTexture2D(glImage, texParams, 0));
}

TextureID RenderingSystem::addTexture(GL::Texture2D &&texture) {
  const TextureID id = textures.size();
  textures.emplace_back(std::move(texture));
  return id;
}

void RenderingSystem::updateQuadCount() {
  size_t numQuads = 0;
  for (auto &writer : writers) {
    numQuads = std::max(numQuads, writer->countQuads());
  }
  
  fillIndicies(numQuads);
  quads.resize(numQuads);
  
  vertArray.bind();
  program.use();
  
  arrayBuf = GL::makeArrayBuffer(numQuads * QUAD_ATTR_SIZE, GL_DYNAMIC_DRAW);
  elemBuf = GL::makeElementBuffer(indicies.data(), numQuads * QUAD_ELEM_SIZE);
  
  fillIndiciesBuf();
  
  GL::attribs<Attribs>();
  
  GL::unuseProgram();
  GL::unbindVertexArray();
}

void RenderingSystem::render(
  const WriterGroup &group,
  const glm::mat3 &viewProj,
  const Frame frame
) {
  if (group.empty()) {
    return;
  }

  vertArray.bind();
  program.use();
  GL::setUniform(viewProjLoc, viewProj);
  
  if (!program.validate()) {
    std::cerr << "Failed to validate program\n";
    std::cerr << "Shader program info log:\n" << program << '\n';
  }
  
  const QuadIter quadIter = quads.begin();
  
  for (WriterID writerID : group) {
    std::unique_ptr<QuadWriter> &writer = writers.at(writerID);
    const size_t writerQuads = writer->numQuads();
    writer->writeQuads(quadIter, frame);
    
    GL::setUniform(colorLoc, writer->getColor(frame));
    textures.at(writer->getTexture()).bind(0);
    fillVertBuf(writerQuads);
    
    glDrawElements(
      GL_TRIANGLES,
      static_cast<GLsizei>(QUAD_INDICIES * writerQuads),
      GL::TypeEnum<ElemType>::type,
      nullptr
    );
    CHECK_OPENGL_ERROR();
  }
  
  GL::unbindTexture2D(0);
  GL::unuseProgram();
  GL::unbindVertexArray();
}

void RenderingSystem::render(
  const WriterID writer,
  const glm::mat3 &viewProj,
  const Frame frame
) {
  static WriterGroup group(1);
  group[0] = writer;
  render(group, viewProj, frame);
}

void RenderingSystem::fillIndicies(const size_t minQuads) {
  if (indicies.size() < minQuads * QUAD_INDICIES) {
    ElemType index = indicies.size() / QUAD_INDICIES * QUAD_VERTS;
    const ElemType lastIndex = minQuads * QUAD_VERTS;
    for (; index != lastIndex; index += 4) {
      indicies.push_back(index + 0);
      indicies.push_back(index + 1);
      indicies.push_back(index + 2);
      indicies.push_back(index + 2);
      indicies.push_back(index + 3);
      indicies.push_back(index + 0);
    }
  }
}

void RenderingSystem::fillIndiciesBuf() {
  const size_t indiciesSize = QUAD_ELEM_SIZE * quads.size();
  glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indiciesSize, indicies.data());
  CHECK_OPENGL_ERROR();
}

void RenderingSystem::fillVertBuf(const size_t numQuads) {
  const size_t vertsSize = sizeof(Quad) * numQuads;
  glBufferSubData(GL_ARRAY_BUFFER, 0, vertsSize, quads.data());
  CHECK_OPENGL_ERROR();
}
