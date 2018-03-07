//
//  rendering system.hpp
//  The Machine
//
//  Created by Indi Kernick on 19/12/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef rendering_system_hpp
#define rendering_system_hpp

#ifdef EMSCRIPTEN
#include <GLES3/gl32.h>
#include <SDL2/SDL.h>
#endif

#include <glm/mat3x3.hpp>
#include "quad writer.hpp"
#include <Simpleton/OpenGL/buffer.hpp>
#include <Simpleton/OpenGL/texture.hpp>
#include <Simpleton/OpenGL/vertex array.hpp>
#include <Simpleton/OpenGL/shader program.hpp>

class RenderingSystem {
public:
  void init();
  void quit();
  
  template <typename WriterClass, typename ...Args>
  WriterID addWriter(Args &&... args) {
    const WriterID id = writers.size();
    writers.emplace_back(std::make_unique<WriterClass>(std::forward<Args>(args)...));
    return id;
  }
  
  QuadWriter &getWriter(WriterID) const;
  
  TextureID addTexture(std::string_view);
  TextureID addTexture(GL::Texture2D &&);
  
  void updateQuadCount();
  void render(const WriterGroup &, const glm::mat3 &, Frame);
  void render(WriterID, const glm::mat3 &, Frame);

private:
  std::vector<std::unique_ptr<QuadWriter>> writers;
  std::vector<GL::Texture2D> textures;
  GL::ArrayBuffer arrayBuf;
  GL::ElementBuffer elemBuf;
  GL::VertexArray vertArray;
  GL::ShaderProgram program;
  
  GLint viewProjLoc;
  GLint texLoc;
  GLint colorLoc;
  
  Quads quads;
  Elems indicies;
  
  void fillIndicies(size_t);
  void fillIndiciesBuf();
  void fillVertBuf(size_t);
};

#endif
