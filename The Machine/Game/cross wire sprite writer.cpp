//
//  cross wire sprite writer.cpp
//  The Machine
//
//  Created by Indi Kernick on 12/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "cross wire sprite writer.hpp"

#include "cross wire component.hpp"
#include "cross wire sprite component.hpp"

namespace {
  using Anim = Unpack::SpriteID CrossWireSprite::*;
  constexpr Anim BOTH = &CrossWireSprite::both;
  constexpr Anim INVERTED = &CrossWireSprite::inverted;
  constexpr Anim HORI_OFF = &CrossWireSprite::horiOff;
  constexpr Anim HORI_ON = &CrossWireSprite::horiOn;
  
  constexpr Math::Dir UP = Math::Dir::UP;
  constexpr Math::Dir RIGHT = Math::Dir::RIGHT;
  
  constexpr Frame BEGIN = 0;
  constexpr Frame END = FRAMES_PER_TICK;
  
  struct Row {
    Anim anim;
    Math::Dir orient;
    Frame start;
    int dir;
  };

  /*
  
  ┏━━━━━━━━┳━━━━━━━━┳━━━━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━━━━┓
  ┃  VERT  ┃  HORI  ┃             ┃          ┃         ┃            ┃
  ┣━━━━┳━━━╋━━━┳━━━━┫  ANIMATION  ┃  ORIENT  ┃  START  ┃  ANIM DIR  ┃
  ┃  P ┃ C ┃ P ┃ C  ┃             ┃          ┃         ┃            ┃
  ┣━━━━╋━━━╋━━━╋━━━━╋━━━━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━━━━┫
  ┃  0 ┃ 0 ┃ 0 ┃ 0  ┃  BOTH       ┃  UP      ┃  BEGIN  ┃  0         ┃
  ┃  0 ┃ 0 ┃ 0 ┃ 1  ┃  HORI_OFF   ┃  RIGHT   ┃  BEGIN  ┃  1         ┃
  ┃  0 ┃ 0 ┃ 1 ┃ 0  ┃  HORI_OFF   ┃  RIGHT   ┃  END    ┃  -1        ┃
  ┃  0 ┃ 0 ┃ 1 ┃ 1  ┃  INVERTED   ┃  UP      ┃  BEGIN  ┃  0         ┃
  ┃  0 ┃ 1 ┃ 0 ┃ 0  ┃  HORI_OFF   ┃  UP      ┃  BEGIN  ┃  1         ┃
  ┃  0 ┃ 1 ┃ 0 ┃ 1  ┃  BOTH       ┃  UP      ┃  BEGIN  ┃  1         ┃
  ┃  0 ┃ 1 ┃ 1 ┃ 0  ┃  INVERTED   ┃  UP      ┃  BEGIN  ┃  1         ┃
  ┃  0 ┃ 1 ┃ 1 ┃ 1  ┃  HORI_ON    ┃  UP      ┃  BEGIN  ┃  1         ┃
  ┃  1 ┃ 0 ┃ 0 ┃ 0  ┃  HORI_OFF   ┃  UP      ┃  END    ┃  -1        ┃
  ┃  1 ┃ 0 ┃ 0 ┃ 1  ┃  INVERTED   ┃  UP      ┃  END    ┃  -1        ┃
  ┃  1 ┃ 0 ┃ 1 ┃ 0  ┃  BOTH       ┃  UP      ┃  END    ┃  -1        ┃
  ┃  1 ┃ 0 ┃ 1 ┃ 1  ┃  HORI_ON    ┃  UP      ┃  END    ┃  -1        ┃
  ┃  1 ┃ 1 ┃ 0 ┃ 0  ┃  INVERTED   ┃  RIGHT   ┃  BEGIN  ┃  0         ┃
  ┃  1 ┃ 1 ┃ 0 ┃ 1  ┃  HORI_ON    ┃  RIGHT   ┃  BEGIN  ┃  1         ┃
  ┃  1 ┃ 1 ┃ 1 ┃ 0  ┃  HORI_ON    ┃  RIGHT   ┃  END    ┃  -1        ┃
  ┃  1 ┃ 1 ┃ 1 ┃ 1  ┃  BOTH       ┃  UP      ┃  END    ┃  0         ┃
  ┗━━━━┻━━━┻━━━┻━━━━┻━━━━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━━━━┛
  
  */
  
  constexpr Row TABLE[16] = {
    {BOTH, UP, BEGIN, 0},
    {HORI_OFF, RIGHT, BEGIN, 1},
    {HORI_OFF, RIGHT, END, -1},
    {INVERTED, UP, BEGIN, 0},
    {HORI_OFF, UP, BEGIN, 1},
    {BOTH, UP, BEGIN, 1},
    {INVERTED, UP, BEGIN, 1},
    {HORI_ON, UP, BEGIN, 1},
    {HORI_OFF, UP, END, -1},
    {INVERTED, UP, END, -1},
    {BOTH, UP, END, -1},
    {HORI_ON, UP, END, -1},
    {INVERTED, RIGHT, BEGIN, 0},
    {HORI_ON, RIGHT, BEGIN, 1},
    {HORI_ON, RIGHT, END, -1},
    {BOTH, UP, END, 0}
  };
}

void CrossWireSpriteWriter::writeQuads(
  QuadIter quadIter,
  ECS::Registry &registry,
  const Spritesheet &sheet,
  const Frame frame
) const {
  const auto view = registry.view<CrossWire, CrossWireSprite, SpritePosition>();
  for (const ECS::EntityID entity : view) {
    const CrossWire cross = view.get<CrossWire>(entity);
    const CrossWireSprite sprite = view.get<CrossWireSprite>(entity);
    SpritePosition spritePos = view.get<SpritePosition>(entity);
    
    const size_t key = (cross.vert.prev << 3) |
                       (cross.vert.curr << 2) |
                       (cross.hori.prev << 1) |
                        cross.hori.curr;
    const Row row = TABLE[key];
    spritePos.orient = row.orient;
    const Unpack::SpriteID animFrame = sprite.*(row.anim) + row.start + frame * row.dir;
    
    writePos(quadIter, spritePos);
    writeTexCoords(quadIter, sheet, animFrame);
    
    ++quadIter;
  }
}

size_t CrossWireSpriteWriter::count(ECS::Registry &registry) const {
  return registry.view<CrossWireSprite>().size();
}