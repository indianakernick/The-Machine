//
//  title screen writer.hpp
//  The Machine
//
//  Created by Indi Kernick on 15/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef title_screen_writer_hpp
#define title_screen_writer_hpp

#include "quad writer.hpp"

class TitleScreenWriter final : public QuadWriter {
public:
  void writeQuads(QuadIter, ECS::Registry &, const Spritesheet &, Frame) const override;
  size_t count(ECS::Registry &) const override;
};

#endif
