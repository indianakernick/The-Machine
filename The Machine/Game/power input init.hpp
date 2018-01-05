//
//  power input init.hpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef power_input_init_hpp
#define power_input_init_hpp

#include "power input component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class PowerInputInit final : public ECS::CompInit<PowerInput> {
public:
  void init(PowerInput &, const json &);
};

#endif
