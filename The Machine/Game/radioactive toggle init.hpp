//
//  radioactive toggle init.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef radioactive_toggle_init_hpp
#define radioactive_toggle_init_hpp

#include <Simpleton/ECS/comp init.hpp>
#include "radioactive toggle component.hpp"

class RadioactiveToggleInit final : public ECS::CompInit<RadioactiveToggle> {
public:
  void init(RadioactiveToggle &, const json &) override;
};

#endif
