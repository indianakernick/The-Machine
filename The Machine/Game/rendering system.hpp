//
//  rendering system.hpp
//  The Machine
//
//  Created by Indi Kernick on 19/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef rendering_system_hpp
#define rendering_system_hpp

#include <glm/mat3x3.hpp>
#include "quad writer.hpp"
#include <Simpleton/ECS/registry.hpp>
#include <Simpleton/OpenGL/buffer.hpp>
#include <Simpleton/OpenGL/texture.hpp>
#include <Simpleton/OpenGL/vertex array.hpp>
#include <Simpleton/OpenGL/shader program.hpp>

class RenderingSystem {
public:
  void init();
  void quit();
  
  template <typename WriterClass>
  void addWriter() {
    writers.emplace_back(std::make_unique<WriterClass>());
  }
  void updateQuadCount(ECS::Registry &);
  void render(ECS::Registry &, const glm::mat3 &, Frame);

private:
  std::vector<std::unique_ptr<QuadWriter>> writers;
  Spritesheet sheet;
  GL::Texture2D texture;
  GL::ArrayBuffer arrayBuf;
  GL::ElementBuffer elemBuf;
  GL::VertexArray vertArray;
  GL::ShaderProgram program;
  size_t numQuads;
  GLint viewProjLoc;
  GLint texLoc;
  
  Quads quads;
  Elems indicies;
  
  void fillIndicies(size_t);
  void fillVBOs();
};

#endif
