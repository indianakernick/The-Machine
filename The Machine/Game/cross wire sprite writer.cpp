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
  
  Unpack::SpriteID getAnimFrame(
    CrossWire cross,
    const CrossWireSprite sprite,
    const Frame frame,
    Math::Dir &orient
  ) {
    return 0;
  }
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
    
    const Unpack::SpriteID animFrame = getAnimFrame(cross, sprite, frame, spritePos.orient);
    writePos(quadIter, spritePos);
    writeTexCoords(quadIter, sheet, animFrame);
    
    ++quadIter;
  }
}

size_t CrossWireSpriteWriter::count(ECS::Registry &registry) const {
  return registry.view<CrossWireSprite>().size();
}
