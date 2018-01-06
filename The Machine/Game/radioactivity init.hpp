//
//  radioactivity init.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef radioactivity_init_hpp
#define radioactivity_init_hpp

#include "radioactivity component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class RadioactivityInit final : public ECS::CompInit<Radioactivity> {
public:
  void init(Radioactivity &, const json &) override;
};

#endif
