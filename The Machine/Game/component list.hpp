//
//  component list.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef component_list_hpp
#define component_list_hpp

#include "exit component.hpp"
#include "gate component.hpp"
#include "wire component.hpp"
#include "delay component.hpp"
#include "power component.hpp"
#include "lever component.hpp"
#include "device component.hpp"
#include "piston component.hpp"
#include "button component.hpp"
#include "weight component.hpp"
#include "position component.hpp"
#include "movement component.hpp"
#include "cross wire component.hpp"
#include "power input component.hpp"
#include "power sprite component.hpp"
#include "power output component.hpp"
#include "static sprite component.hpp"
#include "radioactivity component.hpp"
#include "player action component.hpp"
#include "signal channel component.hpp"
#include "pressure plate component.hpp"
#include <Simpleton/Utils/type list.hpp>
#include "signal receiver component.hpp"
#include "sprite position component.hpp"
#include "static collision component.hpp"
#include "dynamic collision component.hpp"
#include "cross wire sprite component.hpp"
#include "signal transmitter component.hpp"
#include "radioactive toggle component.hpp"
#include "radioactivity sprite component.hpp"
#include "radioactivity detector component.hpp"

using CompList = Utils::TypeList<
  Exit,
  Gate,
  Wire,
  Delay,
  Power,
  Lever,
  Device,
  Piston,
  Button,
  Weight,
  Position,
  Movement,
  CrossWire,
  PowerInput,
  PowerSprite,
  PowerOutput,
  StaticSprite,
  PlayerAction,
  SignalChannel,
  PressurePlate,
  Radioactivity,
  SignalReceiver,
  SpritePosition,
  StaticCollision,
  CrossWireSprite,
  DynamicCollision,
  SignalTransmitter,
  RadioactiveToggle,
  RadioactivitySprite,
  RadioactivityDetector
>;

#endif
