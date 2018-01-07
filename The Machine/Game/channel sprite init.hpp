//
//  channel sprite init.hpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef channel_sprite_init_hpp
#define channel_sprite_init_hpp

#include <Simpleton/ECS/comp init.hpp>
#include "channel sprite component.hpp"

class ChannelSpriteInit final : public ECS::CompInit<ChannelSprite> {
public:
  void init(ChannelSprite &, const json &);
};

#endif
