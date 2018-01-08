//
//  radioactivity sprite writer.hpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef radioactivity_sprite_writer_hpp
#define radioactivity_sprite_writer_hpp

#include "quad writer.hpp"

class RadioactivitySpriteWriter final : public QuadWriter {
public:
  void writeQuads(QuadIter, ECS::Registry &, const Spritesheet &, Frame) const override;
  size_t count(ECS::Registry &) const override;
};

#endif
