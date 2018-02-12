//
//  title screen.cpp
//  The Machine
//
//  Created by Indi Kernick on 15/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "title screen.hpp"

#include "screen manager.hpp"
#include "rendering system.hpp"
#include "title screen writer.hpp"
#include <Simpleton/Utils/profiler.hpp>

class GameScreen;

namespace {
  constexpr Frame LOOP_BEGIN = 480;
  constexpr Frame TOTAL_FRAMES = 720;
}

void TitleScreen::init(std::shared_ptr<RenderingSystem> renderingSystem) {
  PROFILE(TitleScreen::init);

  rendering = renderingSystem;
  
  const TextureID tex = rendering->addTexture("title screen.png");
  writer = rendering->addWriter<TitleScreenWriter>(tex);
  transition.init(*rendering);
  rendering->updateQuadCount();
  
  camera.transform.setOrigin(Cam2D::Origin::BOTTOM_LEFT);
  zoomToFit.setSize({16.0f, 9.0f});
}

void TitleScreen::quit() {
  rendering.reset();
}

void TitleScreen::enter() {
  rendering->updateQuadCount();
}

void TitleScreen::input(const SDL_Event &e) {
  if (e.type == SDL_KEYDOWN && e.key.repeat == 0 && frame >= LOOP_BEGIN) {
    transition.start();
  }
}

void TitleScreen::update(float) {}

void TitleScreen::render(const float aspect, const float delta) {
  PROFILE(TitleScreen::render);

  if (frame == TOTAL_FRAMES) {
    frame = LOOP_BEGIN;
  }
  camera.update({aspect, delta}, zoomToFit);
  rendering->render(writer, camera.transform.toPixels(), frame);
  ++frame;
  
  transition.render(*rendering);
  
  if (transition.isHalfway()) {
    getScreenMan()->transitionTo<GameScreen>();
  }
}
