//
//  screen manager.cpp
//  The Machine
//
//  Created by Indi Kernick on 15/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "screen manager.hpp"

void ScreenManager::removeAll() {
  for (auto &pair : screens) {
    pair.second->screenMan = nullptr;
  }
  screens.clear();
  current = nullptr;
}

void ScreenManager::initAll() {
  for (auto &pair : screens) {
    pair.second->init();
  }
}

void ScreenManager::quitAll() {
  for (auto &pair : screens) {
    pair.second->quit();
  }
}

void ScreenManager::input(const SDL_Event &e) {
  if (current) {
    current->input(e);
  }
}

void ScreenManager::update(const float delta) {
  if (current) {
    current->update(delta);
  }
}

void ScreenManager::render(const float aspect, const float delta) {
  if (current) {
    current->render(aspect, delta);
  }
}

void ScreenManager::transitionTo(const ScreenID next) {
  current = screens.at(next).get();
  current->enter();
}
