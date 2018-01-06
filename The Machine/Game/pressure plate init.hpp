//
//  pressure plate init.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef pressure_plate_init_hpp
#define pressure_plate_init_hpp

#include <Simpleton/ECS/comp init.hpp>
#include "pressure plate component.hpp"

class PressurePlateInit final : public ECS::CompInit<PressurePlate> {
public:
  void init(PressurePlate &, const json &) override;
};

#endif
