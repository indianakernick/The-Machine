//
//  game level.hpp
//  The Machine
//
//  Created by Indi Kernick on 22/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef game_level_hpp
#define game_level_hpp

#include "level manager.hpp"
#include "component list.hpp"
#include "level controller.hpp"
#include <Simpleton/ECS/registry.hpp>
#include <Simpleton/ECS/progress manager.hpp>

extern "C" union SDL_Event;

class GameLevel {
public:
  void init();
  bool input(const SDL_Event &);
  void advanceLevel();
  bool levelChanged() const;
  std::experimental::optional<Pos> loadNewLevel(ECS::Registry &);

private:
  LevelManager<CompList> levels;
  ECS::ProgressManager progress;
  LevelController levelControl;
  std::experimental::optional<ECS::Level> nextLevel;
};

#endif