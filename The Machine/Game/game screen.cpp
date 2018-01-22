//
//  game screen.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "game screen.hpp"

#include <Simpleton/SDL/paths.hpp>
#include <Simpleton/SDL/events.hpp>
#include <Simpleton/Utils/profiler.hpp>

void GameScreen::init(std::shared_ptr<RenderingSystem> renderingSystem) {
  PROFILE(GameScreen::init);

  rendering = renderingSystem;
  
  registry = std::make_shared<ECS::Registry>();
  view.init(*rendering, registry);
  transition.init(*rendering);

  progress.setFilePath(SDL::getSaveDir("Indi Kernick", "The Machine") + "progress.txt");
  progress.readFile();
  levels.setPath(SDL::getResDir() + "level ");
  
  loadLevel(progress.getIncompleteLevel());
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
  const auto controllerLevel = levelControl.getLevel(
    e,
    levels.current(),
    progress.getIncompleteLevel()
  );
  if (controllerLevel) {
    nextLevel = controllerLevel;
  }
  
  logic.input(e);
}

void GameScreen::update(float) {
  PROFILE(GameScreen::update);
  
  if (transition.isRunning()) {
    return;
  }
  
  if (frame == FRAMES_PER_TICK - 1) {
    frame = 0;
  } else {
    ++frame;
    return;
  }

  if (logic.update(*registry)) {
    const ECS::Level current = levels.current();
    if (current != ECS::NULL_LEVEL) {
      progress.finishLevel(current);
      nextLevel = current + 1;
    }
  }
  
  if (nextLevel) {
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
      loadLevel(*nextLevel);
      nextLevel = std::experimental::nullopt;
    }
  } else {
    view.render(*rendering, *registry, frame);
  }
}

bool GameScreen::loadLevel(const ECS::Level level) {
  PROFILE(GameScreen::loadLevel);

  const OptionalObject meta = levels.load(*registry, level);
  if (meta) {
    const Pos levelSize = meta->at("size").get<Pos>();
    view.onLevelLoad(levelSize);
    logic.onLevelLoad(*registry, levelSize);
  }
  rendering->updateQuadCount();
  return static_cast<bool>(meta);
}
