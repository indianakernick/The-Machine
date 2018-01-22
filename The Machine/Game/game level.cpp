//
//  game level.cpp
//  The Machine
//
//  Created by Indi Kernick on 22/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "game level.hpp"

#include <Simpleton/SDL/paths.hpp>

void GameLevel::init() {
  progress.setFilePath(SDL::getSaveDir("Indi Kernick", "The Machine") + "progress.txt");
  progress.readFile();
  levels.setPath(SDL::getResDir() + "level ");
  nextLevel = progress.getIncompleteLevel();
}

bool GameLevel::input(const SDL_Event &e) {
  const auto controllerLevel = levelControl.getLevel(
    e,
    levels.current(),
    progress.getIncompleteLevel()
  );
  if (controllerLevel) {
    nextLevel = controllerLevel;
    return true;
  } else {
    return false;
  }
}

void GameLevel::advanceLevel() {
  const ECS::Level current = levels.current();
  if (current != ECS::NULL_LEVEL) {
    progress.finishLevel(current);
    nextLevel = current + 1;
  }
}

bool GameLevel::levelChanged() const {
  return static_cast<bool>(nextLevel);
}

std::experimental::optional<Pos> GameLevel::loadNewLevel(ECS::Registry &registry) {
  const OptionalObject meta = levels.load(registry, *nextLevel);
  nextLevel = std::experimental::nullopt;
  if (meta) {
    return meta->at("size").get<Pos>();
  } else {
    return std::experimental::nullopt;
  }
}
