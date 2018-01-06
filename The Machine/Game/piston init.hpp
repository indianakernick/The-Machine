//
//  piston init.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef piston_init_hpp
#define piston_init_hpp

#include "piston component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class PistonInit final : public ECS::CompInit<Piston> {
public:
  void init(Piston &, const json &) override;
};

#endif
