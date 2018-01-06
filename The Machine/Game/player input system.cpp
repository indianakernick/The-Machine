//
//  player input system.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "player input system.hpp"

#include <SDL2/SDL_events.h>
#include "movement component.hpp"
#include "player action component.hpp"

namespace {
  void setActionState(ECS::Registry &registry, const bool enabled) {
    auto view = registry.view<PlayerAction>();
    view.each([enabled] (ECS::EntityID, PlayerAction &comp) {
      comp.curr = enabled;
    });
  }
  
  void setDesiredDir(ECS::Registry &registry, const Math::Dir dir) {
    auto view = registry.view<PlayerAction, Movement>();
    view.each([dir] (ECS::EntityID, PlayerAction &, Movement &comp) {
      comp.desiredDir = dir;
    });
  }
}

void playerInputSystem(ECS::Registry &registry, const SDL_Event &e) {
  if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
    const SDL_Scancode key = e.key.keysym.scancode;
    if (key == SDL_SCANCODE_SPACE) {
      setActionState(registry, true);
    } else if (key == SDL_SCANCODE_UP || key == SDL_SCANCODE_W) {
      setDesiredDir(registry, Math::Dir::UP);
    } else if (key == SDL_SCANCODE_RIGHT || key == SDL_SCANCODE_D) {
      setDesiredDir(registry, Math::Dir::RIGHT);
    } else if (key == SDL_SCANCODE_DOWN || key == SDL_SCANCODE_S) {
      setDesiredDir(registry, Math::Dir::DOWN);
    } else if (key == SDL_SCANCODE_LEFT || key == SDL_SCANCODE_A) {
      setDesiredDir(registry, Math::Dir::LEFT);
    }
  } else if (e.type == SDL_KEYUP) {
    if (e.key.keysym.scancode == SDL_SCANCODE_SPACE) {
      setActionState(registry, false);
    }
  }
}
