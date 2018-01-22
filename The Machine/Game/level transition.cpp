//
//  level transition.cpp
//  The Machine
//
//  Created by Indi Kernick on 22/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "level transition.hpp"

#include "transition writer.hpp"
#include <Simpleton/SDL/paths.hpp>

namespace {
  constexpr Frame DURATION = 120;
  constexpr glm::vec3 COLOR = {0.0f, 0.0f, 0.0f};
}

void LevelTransition::init(RenderingSystem &rendering) {
  const TextureID tex = rendering.addTexture("white.png");
  writer = rendering.addWriter<TransitionWriter>(tex, COLOR, DURATION);
}

bool LevelTransition::isRunning() const {
  return state != State::NONE;
}

void LevelTransition::start() {
  state = State::FADE_OUT;
  frame = 0;
}

bool LevelTransition::isHalfway() const {
  return (state == State::FADE_OUT && frame == DURATION / 2);
}

void LevelTransition::render(RenderingSystem &rendering) {
  if (state == State::FADE_OUT) {
    if (frame == DURATION / 2) {
      state = State::FADE_IN;
    }
    rendering.render(writer, {}, frame);
    ++frame;
  } else if (state == State::FADE_IN) {
    rendering.render(writer, {}, frame);
    if (frame == DURATION) {
      state = State::NONE;
    } else {
      ++frame;
    }
  }
}
