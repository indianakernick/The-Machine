//
//  sprite position component.hpp
//  The Machine
//
//  Created by Indi Kernick on 8/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef sprite_position_component_hpp
#define sprite_position_component_hpp

#include <Simpleton/Math/dir.hpp>

struct SpritePosition {
  glm::vec2 pos = {0.0f, 0.0f};
  float depth;
  Math::Dir orient = Math::Dir::UP;
};

#endif
