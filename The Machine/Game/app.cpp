//
//  app.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "app.hpp"

#include <chrono>
#include "game screen.hpp"
#include "title screen.hpp"
#include <Simpleton/SDL/events.hpp>
#include <Simpleton/Utils/profiler.hpp>
#include <Simpleton/Time/main loop.hpp>

void App::runMainloop() {
  init();

  Time::Mainloop<std::chrono::nanoseconds>::varNoSync([this] (const uint64_t delta) {
    return mainloop(delta);
  });

  quit();
}

bool App::mainloop(const uint64_t delta) {
  PROFILE(App::mainloop);
  const float deltaSec = delta / 1'000'000'000.0f;
    
  const bool ok = input();
  update(deltaSec);
  render(deltaSec);
    
  return ok;
}

void App::init() {
  PROFILE(App::init);
  std::cout << "App::init\n";

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
    std::cout << "Initialized SDL\n";
    window = SDL::makeWindow(WINDOW_DESC);
    std::cout << "Opened window\n";
    renderingContext.initVSync(window.get());
    std::cout << "Created rendering context\n";

    renderingContext.preRender();
    std::cout << "Pre rendered\n";
    renderingContext.postRender();
    std::cout << "Post rendered\n";
    
    renderingSystem = std::make_shared<RenderingSystem>();
    renderingSystem->init();
    std::cout << "Initialized rendering system\n";
  }
  
  SDL_PumpEvents();
  std::cout << "Pumped events\n";
  
  {
    PROFILE(Open Audio);
    music.init();
    std::cout << "Initialized audio\n";
  }
  
  screenMan.addScreen<GameScreen>();
  screenMan.addScreen<TitleScreen>();
  
  {
    PROFILE(Initialize Screens);
    screenMan.initAll(renderingSystem);
    std::cout << "Initialized screens\n";
  }
  
  screenMan.transitionTo<TitleScreen>();

  std::cout << "Done App::init()\n";
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
      if (SDL_GetWindowFlags(window.get()) & SDL_WINDOW_FULLSCREEN_DESKTOP) {
        CHECK_SDL_ERROR(SDL_SetWindowFullscreen(window.get(), 0));
      } else {
        CHECK_SDL_ERROR(SDL_SetWindowFullscreen(window.get(), SDL_WINDOW_FULLSCREEN_DESKTOP));
      }
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
