//
//  rendering context.hpp
//  Catastrophe
//
//  Created by Indi Kernick on 4/9/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef rendering_context_hpp
#define rendering_context_hpp

#include <glm/vec2.hpp>
#include <Simpleton/OpenGL/context.hpp>

extern "C" struct SDL_Window;
extern "C" struct SDL_Renderer;

class RenderingContext {
public:
  RenderingContext() = default;
  
  void init(SDL_Window *, bool);
  void quit();
  
  void preRender();
  void postRender();
  
  glm::ivec2 getFrameSize() const;
  SDL_Window *getWindow() const;
  
private:
  SDL_Window *window = nullptr;
  GL::Context context;
  Uint32 minFrameTime = 1000 / 70;
  bool vsync = false;
};

#endif
