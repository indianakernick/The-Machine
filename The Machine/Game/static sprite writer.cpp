//
//  static sprite writer.cpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "static sprite writer.hpp"

#include "static sprite component.hpp"

void StaticSpriteWriter::writeQuads(
  QuadIter quadIter,
  ECS::Registry &registry,
  const Spritesheet &sheet,
  const Frame frame
) const {
  const auto view = registry.view<StaticSprite, SpritePosition>();
  for (const ECS::EntityID entity : view) {
    const StaticSprite sprite = view.get<StaticSprite>(entity);
    const Frame animFrame = sprite.animated ? frame : 0;
    const Unpack::SpriteID spriteID = sprite.sprite + animFrame;
    
    writePos(quadIter, view.get<SpritePosition>(entity));
    writeTexCoords(quadIter, sheet, spriteID);
    
    ++quadIter;
  }
}

size_t StaticSpriteWriter::count(ECS::Registry &registry) const {
  return registry.view<StaticSprite>().size();
}

/*
box                   radioactivity writer
button                power writer
exit                  static writer
gate                  static writer
lever                 power writer
piston base           static writer
piston head           static writer
player                static writer
pressure plate        power writer
radioactive toggle    power writer
radioactive detector  power writer
signal receiver       power writer
signal transmitter    power writer
wall                  static writer
wire                  power writer
*/
