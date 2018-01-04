//
//  game screen.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "game screen.hpp"

#include "component inits.hpp"
#include <Simpleton/SDL/paths.hpp>

void GameScreen::init() {
  compInits.construct<CollisionInit>();
  compInits.constructDefaults();

  progress.setFilePath(SDL::getSaveDir("Indi Kernick", "The Machine") + "progress.txt");
  progress.readFile();
  levels.init(registry, compInits);
  levels.levelPath([] (const ECS::Level level) {
    const std::string levelStr = level == ECS::FINAL_LEVEL ? "final" : std::to_string(level);
    return SDL::getResDir() + "level " + levelStr + ".json";
  });
}

void GameScreen::quit() {
  registry.reset();
  levels.quit();
  
  compInits.destroyAll();
}

void GameScreen::input(const SDL_Event &e) {
  
}

void GameScreen::update(const float delta) {
  
}

void GameScreen::render(const float aspect, const float delta) {
  camera.update(aspect, delta);
  const glm::mat3 viewProj = camera.transform.toPixels();
}
