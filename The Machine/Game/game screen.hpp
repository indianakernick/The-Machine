//
//  game screen.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef game_screen_hpp
#define game_screen_hpp

extern "C" union SDL_Event;

class GameScreen {
public:
  void init();
  void quit();
  void input(const SDL_Event &);
  void update(float);
  void render(float, float);
};

#endif
