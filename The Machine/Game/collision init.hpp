//
//  collision init.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef collision_init_hpp
#define collision_init_hpp

#include "collision component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class CollisionInit final : public ECS::CompInit<Collision> {
public:
  void init(Collision &, const json &) override;
};

#endif
