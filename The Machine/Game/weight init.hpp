//
//  weight init.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef weight_init_hpp
#define weight_init_hpp

#include "weight component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class WeightInit final : public ECS::CompInit<Weight> {
public:
  void init(Weight &, const json &) override;
};

#endif
