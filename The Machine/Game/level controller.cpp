//
//  level controller.cpp
//  The Machine
//
//  Created by Indi Kernick on 17/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "level controller.hpp"

#include <SDL2/SDL_events.h>
#include <Simpleton/SDL/events.hpp>

std::experimental::optional<ECS::Level> LevelController::getLevel(
  const SDL_Event &e,
  const ECS::Level current,
  const ECS::Level progress
) {
  // reload
  if (SDL::keyDown(e, SDL_SCANCODE_R) && current != ECS::NULL_LEVEL) {
    return current;
  }
  
  // next level
  if (SDL::keyDown(e, SDL_SCANCODE_N)) {
    if (current == ECS::NULL_LEVEL) {
      return progress;
    } else if (current + 1 <= progress) {
      return current + 1;
    }
  }
  
  // previous level
  if (SDL::keyDown(e, SDL_SCANCODE_B)) {
    if (current == ECS::NULL_LEVEL) {
      return 0;
    } else if (current != 0) {
      return current - 1;
    }
  }
  
  // start typing level
  if (SDL::keyDown(e, SDL_SCANCODE_L)) {
    choosingLevel = true;
  }
  
  // end typing level
  if (SDL::keyUp(e, SDL_SCANCODE_L)) {
    choosingLevel = false;
    if (!enteredLevel.empty()) {
      const ECS::Level level = enteredLevel.get();
      enteredLevel.clear();
      if (level < progress) {
        return level;
      }
    }
  }
  
  // type level number
  if (SDL::keyDown(e) && choosingLevel) {
    const SDL_Scancode code = SDL::keyCode(e.key);
    //Why did they put SDL_SCANCODE_0 after SDL_SCANCODE_9?
    if (SDL_SCANCODE_1 <= code && code <= SDL_SCANCODE_9) {
      enteredLevel.push(code - SDL_SCANCODE_1 + 1);
    } else if (code == SDL_SCANCODE_0) {
      enteredLevel.push(0);
    }
  }
  
  return std::experimental::nullopt;
}
