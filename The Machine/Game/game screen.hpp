//
//  game screen.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef game_screen_hpp
#define game_screen_hpp

#include "entity grid.hpp"
#include "component list.hpp"
#include "rendering system.hpp"
#include <Simpleton/ECS/registry.hpp>
#include <Simpleton/ECS/comp inits.hpp>
#include <Simpleton/Camera 2D/camera.hpp>
#include <Simpleton/ECS/level manager.hpp>
#include <Simpleton/ECS/progress manager.hpp>

extern "C" union SDL_Event;

class GameScreen {
public:
  void init();
  void quit();
  void input(const SDL_Event &);
  void update(float);
  void render(float, float);

private:
  ECS::Registry registry;
  ECS::CompInits<CompList> compInits;
  ECS::LevelManager<CompList> levels;
  ECS::ProgressManager progress;
  Cam2D::Camera camera;
  EntityGrid grid;
  RenderingSystem rendering;
  Frame frame = 0;
  
  bool loadLevel(ECS::Level);
};

#endif
