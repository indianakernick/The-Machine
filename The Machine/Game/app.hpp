//
//  app.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef app_hpp
#define app_hpp

#include "music player.hpp"
#include "screen manager.hpp"
#include "rendering system.hpp"
#include <Simpleton/SDL/library.hpp>
#include <Simpleton/OpenGL/context.hpp>

class App {
public:
  App() = default;

  bool mainloop(uint64_t);

  void init();
  void quit();

private:
  SDL::Library windowLibrary;
  SDL::Window window;
  GL::Context renderingContext;
  ScreenManager screenMan;
  MusicPlayer music;
  std::shared_ptr<RenderingSystem> renderingSystem;

  bool input();
  void update(float);
  void render(float);
};

#endif
