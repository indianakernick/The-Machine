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
#include "sprite position component.hpp"

void writePos(QuadIter, SpritePosition);
void writeTexCoords(QuadIter, const Spritesheet &, SpriteID);

#endif
