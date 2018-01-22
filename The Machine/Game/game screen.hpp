//
//  game screen.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef game_screen_hpp
#define game_screen_hpp

#include "screen.hpp"
#include "game view.hpp"
#include "game logic.hpp"
#include "level manager.hpp"
#include "component list.hpp"
#include "level transition.hpp"
#include "level controller.hpp"
#include <Simpleton/ECS/registry.hpp>
#include <Simpleton/ECS/progress manager.hpp>

class GameScreen final : public Screen {
public:
  void init(std::shared_ptr<RenderingSystem>) override;
  void quit() override;
  
  void enter() override;
  
  void input(const SDL_Event &) override;
  void update(float) override;
  void render(float, float) override;

private:
  std::shared_ptr<ECS::Registry> registry;
  LevelManager<CompList> levels;
  ECS::ProgressManager progress;
  Frame frame = 0;
  std::shared_ptr<RenderingSystem> rendering;
  LevelController levelControl;
  GameLogic logic;
  GameView view;
  LevelTransition transition;
  std::experimental::optional<ECS::Level> nextLevel;
  
  bool loadLevel(ECS::Level);
};

#endif
