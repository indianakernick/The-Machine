//
//  movement component.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef movement_component_hpp
#define movement_component_hpp

#include <Simpleton/Grid/dir.hpp>

struct Movement {
  Grid::Dir desiredDir = Grid::Dir::NONE;
  Grid::Dir realDir = Grid::Dir::NONE;
};

#endif
