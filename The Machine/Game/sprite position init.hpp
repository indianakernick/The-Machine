//
//  sprite position init.hpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef sprite_position_init_hpp
#define sprite_position_init_hpp

#include "sprite position component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class SpritePositionInit final : public ECS::CompInit<SpritePosition> {
public:
  void init(SpritePosition &, const json &) override;
};

#endif
