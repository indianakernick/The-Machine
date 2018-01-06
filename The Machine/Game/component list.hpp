//
//  component list.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef component_list_hpp
#define component_list_hpp

#include "gate component.hpp"
#include "wire component.hpp"
#include "power component.hpp"
#include "lever component.hpp"
#include "piston component.hpp"
#include "button component.hpp"
#include "weight component.hpp"
#include "position component.hpp"
#include "movement component.hpp"
#include "power input component.hpp"
#include "power output component.hpp"
#include "radioactivity component.hpp"
#include "player action component.hpp"
#include "pressure plate component.hpp"
#include <Simpleton/Utils/type list.hpp>
#include "signal receiver component.hpp"
#include "static collision component.hpp"
#include "dynamic collision component.hpp"
#include "signal transmitter component.hpp"
#include "radioactive toggle component.hpp"
#include "radioactivity detector component.hpp"

using CompList = Utils::TypeList<
  Gate,
  Wire,
  Power,
  Lever,
  Piston,
  Button,
  Weight,
  Position,
  Movement,
  PowerInput,
  PowerOutput,
  PlayerAction,
  PressurePlate,
  Radioactivity,
  SignalReceiver,
  StaticCollision,
  DynamicCollision,
  SignalTransmitter,
  RadioactiveToggle,
  RadioactivityDetector
>;

#endif
