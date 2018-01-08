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
box
  radioactivity writer
button
  power writer
exit
  anim writer
gate
  anim writer
  rotation
lever
  power writer
piston base
  anim writer
  rotation
piston head
  anim writer
  rotation
player
  anim writer
pressure plate
  power writer
radioactive toggle
  power writer
  rotation
radioactive detector
  power writer
  rotation
signal receiver
  power writer
signal transmitter
  power writer
wall
  anim writer
wire
  power writer
  rotation
*/
