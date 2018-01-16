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
#include "rendering helpers.hpp"
#include <Simpleton/ECS/registry.hpp>

class CrossWireSpriteWriter final : public QuadWriter {
public:
  CrossWireSpriteWriter(TextureID, std::shared_ptr<ECS::Registry>, std::shared_ptr<Spritesheet>);

  void writeQuads(QuadIter, Frame) const override;
  TextureID getTexture() const override;
  size_t count() const override;

private:
  TextureID tex;
  std::shared_ptr<ECS::Registry> registry;
  std::shared_ptr<Spritesheet> sheet;
};

#endif
