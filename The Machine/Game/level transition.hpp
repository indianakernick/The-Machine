//
//  level transition.hpp
//  The Machine
//
//  Created by Indi Kernick on 22/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef level_transition_hpp
#define level_transition_hpp

#include "rendering types.hpp"
#include "rendering system.hpp"

class LevelTransition {
public:
  
  void init(RenderingSystem &);
  bool isRunning() const;
  void start();
  bool isHalfway() const;
  void render(RenderingSystem &);
  
private:
  enum class State {
    NONE,
    FADE_OUT,
    FADE_IN
  };

  WriterID writer;
  State state = State::NONE;
  Frame frame = 0;
};

#endif
