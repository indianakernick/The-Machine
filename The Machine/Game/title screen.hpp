//
//  title screen.hpp
//  The Machine
//
//  Created by Indi Kernick on 15/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef title_screen_hpp
#define title_screen_hpp

#include "screen.hpp"
#include "frame type.hpp"
#include "rendering types.hpp"
#include "level transition.hpp"
#include <Simpleton/Camera 2D/camera.hpp>
#include <Simpleton/Camera 2D/zoom to fit.hpp>

class TitleScreen final : public Screen {
public:
  void init(std::shared_ptr<RenderingSystem>) override;
  void quit() override;
  
  void enter() override;
  
  void input(const SDL_Event &) override;
  void update(float) override;
  void render(float, float) override;

private:
  Cam2D::Camera camera;
  std::shared_ptr<RenderingSystem> rendering;
  WriterID writer;
  Frame frame = 0;
  LevelTransition transition;
  Cam2D::ZoomToFit zoomToFit;
};

#endif
