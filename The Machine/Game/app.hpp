//
//  app.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef app_hpp
#define app_hpp

#include "screen manager.hpp"
#include "rendering context.hpp"
#include <Simpleton/SDL/music.hpp>
#include <Simpleton/SDL/library.hpp>
#include <Simpleton/SDL/audio library.hpp>

class App {
public:
  App() = default;
  
  void mainloop();

private:
  SDL::Library windowLibrary;
  SDL::AudioLibrary audioLibrary;
  SDL::Window window;
  RenderingContext renderingContext;
  ScreenManager screenMan;
  SDL::Music music;
  
  void init();
  void quit();
  bool input();
  void update(float);
  void render(float);
};

#endif
