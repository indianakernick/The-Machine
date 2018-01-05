//
//  gate init.hpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef gate_init_hpp
#define gate_init_hpp

#include "gate component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class GateInit final : public ECS::CompInit<Gate> {
public:
  void init(Gate &, const json &) override;
};

#endif
