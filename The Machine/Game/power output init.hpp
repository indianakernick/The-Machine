//
//  power output init.hpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef power_output_init_hpp
#define power_output_init_hpp

#include "power output component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class PowerOutputInit final : public ECS::CompInit<PowerOutput> {
public:
  void init(PowerOutput &, const json &) override;
};

#endif
