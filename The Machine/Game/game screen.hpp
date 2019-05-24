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
#include "game tick.hpp"
#include "game view.hpp"
#include "game logic.hpp"
#include "game level.hpp"
#include "level transition.hpp"
#include <entt/entity/registry.hpp>

class GameScreen final : public Screen {
public:
  void init(std::shared_ptr<RenderingSystem>) override;
  void quit() override;
  
  void enter() override;
  
  void input(const SDL_Event &) override;
  void update(float) override;
  void render(float, float) override;

private:
  std::shared_ptr<entt::registry> registry;
  std::shared_ptr<RenderingSystem> rendering;
  GameLogic logic;
  GameView view;
  LevelTransition transition;
  GameTick tick;
  GameLevel level;
  
  void loadNewLevel();
};

#endif
