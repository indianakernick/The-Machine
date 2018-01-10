//
//  cross wire sprite init.hpp
//  The Machine
//
//  Created by Indi Kernick on 10/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef cross_wire_sprite_init_hpp
#define cross_wire_sprite_init_hpp

#include <Simpleton/ECS/comp init.hpp>
#include "cross wire sprite component.hpp"

class CrossWireSpriteInit final : public ECS::CompInit<CrossWireSprite> {
public:
  void init(CrossWireSprite &, const json &) override;
};

#endif
