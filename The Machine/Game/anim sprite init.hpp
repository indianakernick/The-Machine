//
//  anim sprite init.hpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef anim_sprite_init_hpp
#define anim_sprite_init_hpp

#include "anim sprite component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class AnimSpriteInit final : public ECS::CompInit<AnimSprite> {
public:
  void init(AnimSprite &, const json &) override;
};

#endif
