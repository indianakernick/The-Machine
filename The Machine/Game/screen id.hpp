//
//  screen id.hpp
//  The Machine
//
//  Created by Indi Kernick on 15/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef screen_id_hpp
#define screen_id_hpp

#include <Simpleton/ID/type.hpp>

using ScreenID = size_t;

class Screen;

template <typename ScreenClass>
ScreenID getScreenID() {
  return ID::TypeCounter<ScreenID, ScreenClass, Screen>::get();
}

#endif
