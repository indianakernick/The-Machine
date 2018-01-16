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
#include "entity grid.hpp"
#include "component list.hpp"
#include "rendering system.hpp"
#include "player key states.hpp"
#include <Simpleton/ECS/registry.hpp>
#include <Simpleton/ECS/comp inits.hpp>
#include <Simpleton/Camera 2D/camera.hpp>
#include <Simpleton/ECS/level manager.hpp>
#include <Simpleton/ECS/progress manager.hpp>

class GameScreen final : public Screen {
public:
  void init() override;
  void quit() override;
  
  void enter() override;
  
  void input(const SDL_Event &) override;
  void update(float) override;
  void render(float, float) override;

private:
  std::shared_ptr<ECS::Registry> registry;
  std::shared_ptr<Spritesheet> sheet;
  ECS::CompInits<CompList> compInits;
  ECS::LevelManager<CompList> levels;
  ECS::ProgressManager progress;
  Cam2D::Camera camera;
  EntityGrid grid;
  RenderingSystem rendering;
  PlayerKeyStates playerInput;
  Frame frame = 0;
  
  bool loadLevel(ECS::Level);
};

#endif
