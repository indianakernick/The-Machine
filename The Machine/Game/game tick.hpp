//
//  game tick.hpp
//  The Machine
//
//  Created by Indi Kernick on 22/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef game_tick_hpp
#define game_tick_hpp

#include "frame type.hpp"

class GameTick {
public:
  void update();
  bool isGameTick() const;
  Frame getAnimFrame() const;
  
private:
  Frame frame = FRAMES_PER_TICK - 1;
};

#endif
