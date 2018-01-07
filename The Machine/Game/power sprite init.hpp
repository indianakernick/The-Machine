//
//  power sprite init.hpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef power_sprite_init_hpp
#define power_sprite_init_hpp

#include "power sprite component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class PowerSpriteInit final : public ECS::CompInit<PowerSprite> {
public:
  void init(PowerSprite &, const json &) override;
};

#endif
