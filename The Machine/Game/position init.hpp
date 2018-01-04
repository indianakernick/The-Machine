//
//  position init.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef position_init_hpp
#define position_init_hpp

#include "position component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class PositionInit final : public ECS::CompInit<Position> {
public:
  void init(Position &, const json &) override;
};

#endif
