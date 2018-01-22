//
//  game tick.cpp
//  The Machine
//
//  Created by Indi Kernick on 22/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "game tick.hpp"

void GameTick::update() {
  if (frame == FRAMES_PER_TICK - 1) {
    frame = 0;
  } else {
    ++frame;
  }
}

bool GameTick::isGameTick() const {
  return frame == 0;
}

Frame GameTick::getAnimFrame() const {
  return frame;
}
