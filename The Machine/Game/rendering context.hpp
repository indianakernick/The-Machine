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

#ifdef EMSCRIPTEN
#include <SDL2/SDL.h>
#include <GLES3/gl32.h>
#else
#include <Simpleton/OpenGL/context.hpp>
#endif

extern "C" struct SDL_Window;
extern "C" struct SDL_Renderer;

class RenderingContext {
public:
  RenderingContext() = default;
  
  void init(SDL_Window *);
  void initLimitFPS(SDL_Window *, uint32_t);
  void initVSync(SDL_Window *);
  void quit();
  
  void preRender();
  void postRender();
  
  glm::ivec2 getFrameSize() const;
  SDL_Window *getWindow() const;
  
private:
#ifdef EMSCRIPTEN
  SDL_Renderer *context;
#else
  GL::Context context;
#endif
  SDL_Window *window = nullptr;
  Uint32 minFrameTime = 0;
  
  void initImpl(SDL_Window *, bool);
};

#endif
