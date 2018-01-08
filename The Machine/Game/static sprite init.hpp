//
//  static sprite init.hpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef static_sprite_init_hpp
#define static_sprite_init_hpp

#include "static sprite component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class StaticSpriteInit final : public ECS::CompInit<StaticSprite> {
public:
  void init(StaticSprite &, const json &) override;
};

#endif
