//
//  app.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef app_hpp
#define app_hpp

#include "game screen.hpp"
#include "rendering context.hpp"
#include <Simpleton/SDL/library.hpp>

class App {
public:
  App() = default;
  
  void mainloop();

private:
  SDL::Library windowLibrary;
  SDL::Window window;
  RenderingContext renderingContext;
  GameScreen game;
  
  void init();
  void quit();
  bool input();
  void update(float);
  void render(float);
};

#endif
