//
//  wire init.hpp
//  The Machine
//
//  Created by Indi Kernick on 5/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef wire_init_hpp
#define wire_init_hpp

#include "wire component.hpp"
#include <Simpleton/ECS/comp init.hpp>

class WireInit final : public ECS::CompInit<Wire> {
public:
  void init(Wire &, const json &) override;
};

#endif
