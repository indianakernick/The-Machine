//
//  rendering context.cpp
//  Catastrophe
//
//  Created by Indi Kernick on 4/9/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#include "rendering context.hpp"

#include <SDL2/SDL.h>
#include <Simpleton/SDL/error.hpp>

void RenderingContext::init(SDL_Window *newWindow, const bool vsyncEnabled) {
  vsync = vsyncEnabled;

  window = newWindow;
  GL::ContextParams params;
  params.vsync = vsync;
  params.majorVersion = 4;
  params.minorVersion = 1;
  context = GL::makeContext(window, params);
  
  glEnable(GL_DEPTH_TEST);
  
  SDL_DisplayMode mode;
  CHECK_SDL_ERROR(SDL_GetWindowDisplayMode(window, &mode));
  if (mode.refresh_rate != 0) {
    minFrameTime = 1000 / (mode.refresh_rate + 10);
  }
}

void RenderingContext::quit() {
  context = nullptr;
  window = nullptr;
}

void RenderingContext::preRender() {
  glm::ivec2 size;
  SDL_GetWindowSize(window, &size.x, &size.y);
  glViewport(0, 0, size.x, size.y);
  CHECK_OPENGL_ERROR();
  
  GL::clearFrame();
}

void RenderingContext::postRender() {
  if (vsync) {
    const Uint32 start = SDL_GetTicks();
    SDL_GL_SwapWindow(window);
    const Uint32 end = SDL_GetTicks();
    
    const Uint32 swapTime = end - start;
    if (swapTime < minFrameTime) {
      SDL_Delay(minFrameTime - swapTime);
    }
  } else {
    SDL_GL_SwapWindow(window);
  }
}

glm::ivec2 RenderingContext::getFrameSize() const {
  glm::ivec2 size;
  SDL_GL_GetDrawableSize(window, &size.x, &size.y);
  return size;
}

SDL_Window *RenderingContext::getWindow() const {
  return window;
}
