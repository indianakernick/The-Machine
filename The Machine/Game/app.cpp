//
//  app.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "app.hpp"

#include "game screen.hpp"
#include "title screen.hpp"
#include <Simpleton/SDL/events.hpp>
#include <Simpleton/Utils/profiler.hpp>

bool App::mainloop(const uint64_t deltaNano) {
  PROFILE(App::mainloop);
  const float deltaSec = deltaNano / 1'000'000'000.0f;
    
  const bool ok = input();
  update(deltaSec);
  render(deltaSec);
    
  return ok;
}

void App::init() {
  PROFILE(App::init);

  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc99-extensions"

  const SDL::Window::Desc WINDOW_DESC = {
    .title = "The Machine",
    .size = {1280, 720},
    .resizable = true,
    .openGL = true
  };
  
  #pragma clang diagnostic pop

  {
    PROFILE(Open Window);
    windowLibrary = SDL::makeLibrary(SDL_INIT_EVENTS | SDL_INIT_AUDIO);
    window = SDL::makeWindow(WINDOW_DESC);
    renderingContext.initVSync(window.get());
    glEnable(GL_DEPTH_TEST);

    renderingContext.preRender();
    renderingContext.postRender();
    
    renderingSystem = std::make_shared<RenderingSystem>();
    renderingSystem->init();
  }
  
  SDL_PumpEvents();
  
  {
    PROFILE(Open Audio);
    music.init();
  }
  
  screenMan.addScreen<GameScreen>();
  screenMan.addScreen<TitleScreen>();
  
  {
    PROFILE(Initialize Screens);
    screenMan.initAll(renderingSystem);
  }
  
  screenMan.transitionTo<TitleScreen>();
}

void App::quit() {
  PROFILE(App::quit);

  screenMan.quitAll();
  screenMan.removeAll();
  music.quit();
  renderingSystem->quit();
  renderingSystem.reset();
  renderingContext.quit();
  window.reset();
  windowLibrary.reset();
}

bool App::input() {
  PROFILE(App::input);
  
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      return false;
    } else if (SDL::keyDown(e, SDL_SCANCODE_M)) {
      music.togglePlaying();
    } else if (SDL::keyDown(e, SDL_SCANCODE_F)) {
      window.toggleFullscreen();
    } else {
      screenMan.input(e);
    }
  }
  return true;
}

void App::update(const float delta) {
  PROFILE(App::update);

  screenMan.update(delta);
}

void App::render(const float delta) {
  PROFILE(App::render);
  
  renderingContext.preRender();
  const glm::ivec2 windowSize = window.size();
  const float aspect = static_cast<float>(windowSize.x) / windowSize.y;
  screenMan.render(aspect, delta);
  renderingContext.postRender();
}
