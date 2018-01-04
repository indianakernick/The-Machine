//
//  app.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "app.hpp"

#include <chrono>
#include <Simpleton/Time/main loop.hpp>

void App::mainloop() {
  init();
  
  Time::Mainloop<std::chrono::nanoseconds>::varNoSync([this] (const uint64_t delta) {
    const float deltaSec = delta / 1'000'000'000.0f;
    
    const bool ok = input();
    update(deltaSec);
    render(deltaSec);
    
    return ok;
  });
  
  quit();
}

void App::init() {
  const SDL::Window::Desc WINDOW_DESC = {
    .title = "The Machine",
    .size = {1280, 720},
    .resizable = true,
    .openGL = true
  };

  windowLibrary = SDL::makeLibrary(SDL_INIT_EVENTS);
  window = SDL::makeWindow(WINDOW_DESC);
  renderingContext.init(window.get(), true);
}

void App::quit() {
  renderingContext.quit();
  window.reset();
  windowLibrary.reset();
}

bool App::input() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      return false;
    } else {
      // pass input event to game screen
    }
  }
  return true;
}

void App::update(const float delta) {
  // update game
}

void App::render(const float delta) {
  renderingContext.preRender();
  const glm::ivec2 windowSize = window.size();
  const float aspect = static_cast<float>(windowSize.x) / windowSize.y;
  // render game
  renderingContext.postRender();
}
