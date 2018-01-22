//
//  game logic.cpp
//  The Machine
//
//  Created by Indi Kernick on 22/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "game logic.hpp"

#include "wire system.hpp"
#include "gate system.hpp"
#include "exit system.hpp"
#include "delay system.hpp"
#include "lever system.hpp"
#include "piston system.hpp"
#include "button system.hpp"
#include "move dir system.hpp"
#include "init grid system.hpp"
#include "update pos system.hpp"
#include "shift power system.hpp"
#include "power input system.hpp"
#include "player input system.hpp"
#include "device input system.hpp"
#include "clear real dir system.hpp"
#include "pressure plate system.hpp"
#include "signal receiver system.hpp"
#include "shift cross wire system.hpp"
#include "clear desired dir system.hpp"
#include "clear player input system.hpp"
#include "radioactive toggle system.hpp"
#include "shift player action system.hpp"
#include "shift radioactivity system.hpp"
#include "player input response system.hpp"
#include "signal channel toggle system.hpp"
#include "radioactivity detector system.hpp"

bool GameLogic::input(const SDL_Event &e) {
  return playerInputSystem(playerInput, e);
}

void GameLogic::onLevelLoad(ECS::Registry &registry, const Pos levelSize) {
  grid = EntityGrid(levelSize);
  initGridSystem(registry, grid);
}

void GameLogic::update(ECS::Registry &registry) {
  shiftPowerSystem(registry);
  shiftCrossWireSystem(registry);
  shiftPlayerActionSystem(registry);
  shiftRadioactivitySystem(registry);
  
  playerInputResponseSystem(registry, playerInput);
  clearPlayerInputSystem(playerInput);
  
  updatePosSystem(registry, grid);
  
  signalChannelToggleSystem(registry, grid);
  radioactivityDetectorSystem(registry, grid);
  signalReceiverSystem(registry);
  pressurePlateSystem(registry, grid);
  leverSystem(registry, grid);
  buttonSystem(registry, grid);
  
  powerInputSystem(registry, grid);
  gateSystem(registry);
  delaySystem(registry);
  wireSystem(registry, grid);
  deviceInputSystem(registry);
  
  radioactiveToggleSystem(registry, grid);
  pistonSystem(registry, grid);
  
  clearRealDirSystem(registry);
  moveDirSystem(registry, grid);
  clearDesiredDirSystem(registry);
}

bool GameLogic::exitLevel(ECS::Registry &registry) {
  return exitSystem(registry, grid);
}
