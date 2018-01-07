//
//  radioactivity sprite init.hpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef radioactivity_sprite_init_hpp
#define radioactivity_sprite_init_hpp

#include <Simpleton/ECS/comp init.hpp>
#include "radioactivity sprite component.hpp"

class RadioactivitySpriteInit final : public ECS::CompInit<RadioactivitySprite> {
public:
  void init(RadioactivitySprite &, const json &) override;
};

#endif
