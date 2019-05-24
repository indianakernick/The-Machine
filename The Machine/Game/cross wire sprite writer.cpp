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
  using Anim = Sprite::ID CrossWireSprite::*;
  constexpr Anim BOTH = &CrossWireSprite::both;
  constexpr Anim INVERTED = &CrossWireSprite::inverted;
  constexpr Anim HORI_OFF = &CrossWireSprite::horiOff;
  constexpr Anim HORI_ON = &CrossWireSprite::horiOn;
  
  constexpr Grid::Dir UP = Grid::Dir::up;
  constexpr Grid::Dir RIGHT = Grid::Dir::right;
  
  constexpr Frame BEGIN = 0;
  constexpr Frame END = FRAMES_PER_TICK;
  
  struct Row {
    Anim anim;
    Grid::Dir orient;
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

CrossWireSpriteWriter::CrossWireSpriteWriter(
  const TextureID tex,
  std::shared_ptr<entt::registry> registry,
  std::shared_ptr<Sheet> sheet
) : tex(tex),
    registry(registry),
    sheet(sheet) {}

void CrossWireSpriteWriter::writeQuads(QuadIter quadIter, const Frame frame) const {
  const auto view = registry->view<CrossWire, CrossWireSprite, SpritePosition>();
  for (const entt::entity entity : view) {
    const CrossWire cross = view.get<CrossWire>(entity);
    const CrossWireSprite sprite = view.get<CrossWireSprite>(entity);
    SpritePosition spritePos = view.get<SpritePosition>(entity);
    
    const size_t key = (cross.vert.prev << 3) |
                       (cross.vert.curr << 2) |
                       (cross.hori.prev << 1) |
                        cross.hori.curr;
    const Row row = TABLE[key];
    spritePos.orient = row.orient;
    const Sprite::ID animFrame = sprite.*(row.anim) + row.start + frame * row.dir;
    
    writePos(quadIter, spritePos);
    writeTexCoords(quadIter, *sheet, animFrame);
    
    ++quadIter;
  }
}

TextureID CrossWireSpriteWriter::getTexture() const {
  return tex;
}

size_t CrossWireSpriteWriter::count() const {
  return registry->view<CrossWireSprite>().size();
}
