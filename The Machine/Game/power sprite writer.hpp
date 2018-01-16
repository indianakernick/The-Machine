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
  PowerSpriteWriter(TextureID, std::shared_ptr<ECS::Registry>, std::shared_ptr<Spritesheet>);

  void writeQuads(QuadIter, Frame) const override;
  TextureID getTexture() const override;
  size_t count() const override;

private:
  TextureID tex;
  std::shared_ptr<ECS::Registry> registry;
  std::shared_ptr<Spritesheet> sheet;
};

#endif
