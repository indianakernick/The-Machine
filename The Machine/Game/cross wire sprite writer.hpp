//
//  cross wire sprite writer.hpp
//  The Machine
//
//  Created by Indi Kernick on 12/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef cross_wire_sprite_writer_hpp
#define cross_wire_sprite_writer_hpp

#include "quad writer.hpp"

class CrossWireSpriteWriter final : public QuadWriter {
public:
  void writeQuads(QuadIter, ECS::Registry &, const Spritesheet &, Frame) const override;
  size_t count(ECS::Registry &) const override;
};

#endif
