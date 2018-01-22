//
//  game logic.hpp
//  The Machine
//
//  Created by Indi Kernick on 22/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef game_logic_hpp
#define game_logic_hpp

#include "frame type.hpp"
#include "entity grid.hpp"
#include "player key states.hpp"
#include <Simpleton/ECS/registry.hpp>

extern "C" union SDL_Event;

class GameLogic {
public:
  bool input(const SDL_Event &);
  void onLevelLoad(ECS::Registry &, Pos);
  void update(ECS::Registry &);
  bool exitLevel(ECS::Registry &);

private:
  EntityGrid grid;
  PlayerKeyStates playerInput;
};

#endif
