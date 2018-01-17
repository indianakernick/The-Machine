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
#include "rendering system.hpp"
#include <Simpleton/Camera 2D/camera.hpp>

class TitleScreen final : public Screen {
public:
  void init() override;
  void quit() override;
  
  void enter() override;
  
  void input(const SDL_Event &) override;
  void update(float) override;
  void render(float, float) override;

private:
  Cam2D::Camera camera;
  RenderingSystem rendering;
  WriterGroup quadWriters;
  Frame frame = 0;
};

#endif
