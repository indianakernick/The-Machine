//
//  game screen.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "game screen.hpp"

#include <Simpleton/SDL/events.hpp>
#include <Simpleton/Utils/profiler.hpp>

void GameScreen::init(std::shared_ptr<RenderingSystem> renderingSystem) {
  PROFILE(GameScreen::init);

  rendering = renderingSystem;
  
  registry = std::make_shared<ECS::Registry>();
  view.init(*rendering, registry);
  transition.init(*rendering);
  level.init();
  loadNewLevel();
}

void GameScreen::quit() {
  PROFILE(GameScreen::quit);
  
  view.quit();
  registry.reset();
  rendering.reset();
}

void GameScreen::enter() {
  rendering->updateQuadCount();
}

void GameScreen::input(const SDL_Event &e) {
  level.input(e);
  logic.input(e);
}

void GameScreen::update(float) {
  PROFILE(GameScreen::update);
  
  if (transition.isRunning()) {
    return;
  }
  
  tick.update();
  if (!tick.isGameTick()) {
    return;
  }

  logic.update(*registry);
  if (logic.exitLevel(*registry)) {
    level.advanceLevel();
  }
  
  if (level.levelChanged()) {
    transition.start();
  }
}

void GameScreen::render(const float aspect, const float delta) {
  PROFILE(GameScreen::render);
  
  view.updateCam(aspect, delta);
  
  if (transition.isRunning()) {
    view.render(*rendering, *registry, 0);
    transition.render(*rendering);
    if (transition.isHalfway()) {
      loadNewLevel();
    }
  } else {
    view.render(*rendering, *registry, tick.getAnimFrame());
  }
}

void GameScreen::loadNewLevel() {
  PROFILE(GameScreen::loadLevel);

  const auto levelSize = level.loadNewLevel(*registry);
  if (levelSize) {
    view.onLevelLoad(*levelSize);
    logic.onLevelLoad(*registry, *levelSize);
  }
  rendering->updateQuadCount();
}
