//
//  dynamic collision init.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef dynamic_collision_init_hpp
#define dynamic_collision_init_hpp

#include <Simpleton/ECS/comp inits.hpp>
#include "dynamic collision component.hpp"

class DynamicCollisionInit final : public ECS::CompInit<DynamicCollision> {
public:
  void init(DynamicCollision &, const json &) override;
};

#endif
