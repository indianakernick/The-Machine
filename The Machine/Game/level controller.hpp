//
//  level controller.hpp
//  The Machine
//
//  Created by Indi Kernick on 17/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef level_controller_hpp
#define level_controller_hpp

#include <optional>
#include <Simpleton/ECS/level.hpp>
#include <Simpleton/Math/digit stack.hpp>

extern "C" union SDL_Event;

class LevelController {
public:
  std::optional<ECS::Level> getLevel(
    const SDL_Event &,
    ECS::Level current,
    ECS::Level progress
  );
  
private:
  Math::DigitStack<ECS::Level> enteredLevel;
  bool choosingLevel = false;
};

#endif
