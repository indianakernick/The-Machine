//
//  delay init.hpp
//  The Machine
//
//  Created by Indi Kernick on 13/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef delay_init_hpp
#define delay_init_hpp

#include "delay component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class DelayInit final : public ECS::CompInit<Delay> {
public:
  void init(Delay &, const json &) override;
};

#endif
