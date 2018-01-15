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
#include "title screen writer.hpp"
#include <Simpleton/Camera 2D/zoom to fit.hpp>

namespace {
  constexpr Frame LOOP_BEGIN = 300;
  constexpr Frame TOTAL_FRAMES = 540;
}

void TitleScreen::init() {
  rendering.init("title screen");
  rendering.addWriter<TitleScreenWriter>();
  ECS::Registry fakeRegistry;
  rendering.updateQuadCount(fakeRegistry);
  
  camera.transform.setOrigin(Cam2D::Origin::BOTTOM_LEFT);
  camera.targetZoom = std::make_unique<Cam2D::ZoomToFit>(glm::vec2(16.0f, 9.0f));
}

void TitleScreen::quit() {
  rendering.quit();
}

void TitleScreen::enter() {
  ECS::Registry fakeRegistry;
  rendering.updateQuadCount(fakeRegistry);
}

void TitleScreen::input(const SDL_Event &e) {
  if (e.type == SDL_KEYDOWN && frame >= LOOP_BEGIN) {
    getScreenMan()->transitionTo<GameScreen>();
  }
}

void TitleScreen::update(float) {}

void TitleScreen::render(const float aspect, const float delta) {
  if (frame == TOTAL_FRAMES) {
    frame = LOOP_BEGIN;
  }
  camera.update(aspect, delta);
  ECS::Registry fakeRegistry;
  rendering.render(fakeRegistry, camera.transform.toPixels(), frame);
  ++frame;
}
