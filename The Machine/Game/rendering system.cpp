//
//  rendering system.cpp
//  The Machine
//
//  Created by Indi Kernick on 19/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "rendering system.hpp"

#include <fstream>
#include <Surface/load.hpp>
#include <Simpleton/SDL/paths.hpp>
#include <Simpleton/Utils/profiler.hpp>
#include <Simpleton/OpenGL/uniforms.hpp>
#include <Simpleton/OpenGL/attrib pointer.hpp>

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
}

void RenderingSystem::init() {
  PROFILE(RenderingSystem::init);

  vertArray = GL::makeVertexArray();
  
  std::ifstream vertFile(SDL::getResDir() + "sprite shader.vert");
  std::ifstream fragFile(SDL::getResDir() + "sprite shader.frag");
  program = GL::makeShaderProgram(
    GL::makeVertShader(vertFile),
    GL::makeFragShader(fragFile)
  );
  
  viewProjLoc = program.getUniformLoc("viewProj");
  texLoc = program.getUniformLoc("tex");
  
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

TextureID RenderingSystem::addTexture(const std::string_view name) {
  const Surface image = loadSurfaceRGBA(SDL::getResDir() + std::string(name));
  const GL::Image2D glImage = {
    image.data(),
    static_cast<GLsizei>(image.width()),
    static_cast<GLsizei>(image.height())
  };
  GL::TexParams2D texParams;
  texParams.setWrap(GL_CLAMP_TO_EDGE);
  texParams.setFilter(GL_NEAREST);
  const TextureID id = textures.size();
  textures.emplace_back(GL::makeTexture2D(glImage, texParams, 0));
  return id;
}

void RenderingSystem::updateQuadCount() {
  numQuads = 0;
  for (auto &writer : writers) {
    numQuads += writer->countQuads();
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

void RenderingSystem::render(const glm::mat3 &viewProj, const Frame frame) {
  vertArray.bind();
  program.use();
  GL::setUniform(viewProjLoc, viewProj);
  
  if (!program.validate()) {
    std::cerr << "Failed to validate program\n";
    std::cerr << "Shader program info log:\n" << program << '\n';
  }
  
  QuadIter quadIter = quads.begin();
  size_t offset = 0;
  
  for (auto &writer : writers) {
    const size_t writerQuads = writer->numQuads();
  
    writer->writeQuads(quadIter, frame);
    quadIter += writerQuads;
    
    textures.at(writer->getTexture()).bind(0);
    fillVertBuf(offset, writerQuads);
    
    glDrawElements(
      GL_TRIANGLES,
      static_cast<GLsizei>(QUAD_INDICIES * writerQuads),
      GL::TypeEnum<ElemType>::type,
      reinterpret_cast<const GLvoid *>(offset * QUAD_ELEM_SIZE)
    );
    CHECK_OPENGL_ERROR();
    
    offset += writerQuads;
  }
  
  GL::unbindTexture2D(0);
  GL::unuseProgram();
  GL::unbindVertexArray();
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
  const size_t indiciesSize = sizeof(ElemType) * QUAD_INDICIES * numQuads;
  glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, indiciesSize, indicies.data());
  CHECK_OPENGL_ERROR();
}

void RenderingSystem::fillVertBuf(const size_t quadIndex, const size_t numQuads) {
  const size_t vertsSize = sizeof(Quad) * numQuads;
  glBufferSubData(GL_ARRAY_BUFFER, sizeof(Quad) * quadIndex, vertsSize, quads.data() + quadIndex);
  CHECK_OPENGL_ERROR();
}
