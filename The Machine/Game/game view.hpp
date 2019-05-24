//
//  game view.hpp
//  The Machine
//
//  Created by Indi Kernick on 22/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef game_view_hpp
#define game_view_hpp

#include "rendering types.hpp"
#include "rendering system.hpp"
#include <Simpleton/Sprite/sheet.hpp>
#include <entt/entity/registry.hpp>
#include <Simpleton/Camera 2D/camera.hpp>
#include <Simpleton/Camera 2D/zoom to fit.hpp>

class GameView {
public:
  void init(RenderingSystem &, std::shared_ptr<entt::registry>);
  void quit();
  void onLevelLoad(Pos);
  void updateCam(float, float);
  void render(RenderingSystem &, entt::registry &, Frame);
  
private:
  std::shared_ptr<Sprite::Sheet> sheet;
  WriterGroup writers;
  Cam2D::Camera camera;
  Cam2D::ZoomToFit zoomToFit;
};

#endif
