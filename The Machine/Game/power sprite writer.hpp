//
//  power sprite writer.hpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef power_sprite_writer_hpp
#define power_sprite_writer_hpp

#include "quad writer.hpp"

class PowerSpriteWriter final : public QuadWriter {
public:
  void writeQuads(QuadIter, ECS::Registry &, const Spritesheet &, Frame) const override;
  size_t count(ECS::Registry &) const override;
};

#endif
