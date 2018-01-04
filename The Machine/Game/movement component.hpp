//
//  movement component.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef movement_component_hpp
#define movement_component_hpp

#include <Simpleton/Math/dir.hpp>

struct Movement {
  Math::Dir desiredDir;
  Math::Dir realDir;
};

#endif
