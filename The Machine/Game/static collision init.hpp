//
//  static collision init.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef static_collision_init_hpp
#define static_collision_init_hpp

#include <Simpleton/ECS/comp init.hpp>
#include "static collision component.hpp"

class StaticCollisionInit final : public ECS::CompInit<StaticCollision> {
public:
  void init(StaticCollision &, const json &) override;
};

#endif
