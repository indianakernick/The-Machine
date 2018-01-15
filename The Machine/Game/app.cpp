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
#include <Simpleton/Utils/profiler.hpp>
#include <Simpleton/Time/main loop.hpp>

void App::mainloop() {
  PROFILE(App::mainloop);

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
    
    renderingContext.preRender();
    renderingContext.postRender();
  }
  
  SDL_PumpEvents();
  
  {
    PROFILE(Open Audio);
    SDL::AudioLibParams audioParams;
    audioParams.frequency = 44100;
    audioLibrary = SDL::makeAudioLibrary(audioParams);
    music.init();
  }
  
  screenMan.addScreen<GameScreen>();
  screenMan.addScreen<TitleScreen>();
  
  {
    PROFILE(Initialize Screens);
    screenMan.initAll();
  }
  
  screenMan.transitionTo<TitleScreen>();
}

void App::quit() {
  PROFILE(App::quit);

  screenMan.quitAll();
  screenMan.removeAll();
  music.quit();
  audioLibrary.reset();
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
