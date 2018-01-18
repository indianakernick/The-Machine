//
//  title screen.cpp
//  The Machine
//
//  Created by Indi Kernick on 15/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "title screen.hpp"

#include "game screen.hpp"
#include "screen manager.hpp"
#include "rendering system.hpp"
#include "title screen writer.hpp"
#include <Simpleton/Utils/profiler.hpp>
#include <Simpleton/Camera 2D/zoom to fit.hpp>

namespace {
  constexpr Frame LOOP_BEGIN = 480;
  constexpr Frame TOTAL_FRAMES = 720;
}

void TitleScreen::init(std::shared_ptr<RenderingSystem> renderingSystem) {
  PROFILE(TitleScreen::init);

  rendering = renderingSystem;
  
  const TextureID tex = rendering->addTexture("title screen.png");
  quadWriters.push_back(rendering->addWriter<TitleScreenWriter>(tex));
  rendering->updateQuadCount();
  
  camera.transform.setOrigin(Cam2D::Origin::BOTTOM_LEFT);
  camera.targetZoom = std::make_unique<Cam2D::ZoomToFit>(glm::vec2(16.0f, 9.0f));
}

void TitleScreen::quit() {
  rendering.reset();
}

void TitleScreen::enter() {
  rendering->updateQuadCount();
}

void TitleScreen::input(const SDL_Event &e) {
  // @TODO uncomment
  if (e.type == SDL_KEYDOWN /* && frame >= LOOP_BEGIN */) {
    getScreenMan()->transitionTo<GameScreen>();
  }
}

void TitleScreen::update(float) {}

void TitleScreen::render(const float aspect, const float delta) {
  PROFILE(TitleScreen::render);

  if (frame == TOTAL_FRAMES) {
    frame = LOOP_BEGIN;
  }
  camera.update(aspect, delta);
  rendering->render(quadWriters, camera.transform.toPixels(), frame);
  ++frame;
}
