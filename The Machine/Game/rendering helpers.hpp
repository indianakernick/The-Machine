//
//  rendering helpers.hpp
//  The Machine
//
//  Created by Indi Kernick on 16/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef rendering_helpers_hpp
#define rendering_helpers_hpp

#include "rendering types.hpp"
#include <Simpleton/Sprite/sheet.hpp>
#include "sprite position component.hpp"

using Sprite::Sheet;

void writePos(QuadIter, SpritePosition);
void writeTexCoords(QuadIter, const Sheet &, Sprite::ID);

#endif
