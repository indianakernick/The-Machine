//
//  game view.hpp
//  The Machine
//
//  Created by Indi Kernick on 22/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef game_view_hpp
#define game_view_hpp

#include <unpacker.hpp>
#include "rendering types.hpp"
#include "rendering system.hpp"
#include <Simpleton/ECS/registry.hpp>
#include <Simpleton/Camera 2D/camera.hpp>

class GameView {
public:
  void init(RenderingSystem &, std::shared_ptr<ECS::Registry>);
  void quit();
  void onLevelLoad(Pos);
  void updateCam(float, float);
  void render(RenderingSystem &, ECS::Registry &, Frame);
  
private:
  std::shared_ptr<Unpack::Spritesheet> sheet;
  WriterGroup writers;
  Cam2D::Camera camera;
};

#endif
