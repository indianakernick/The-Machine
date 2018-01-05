//
//  component list.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef component_list_hpp
#define component_list_hpp

#include "power component.hpp"
#include "position component.hpp"
#include "movement component.hpp"
#include "player action component.hpp"
#include <Simpleton/Utils/type list.hpp>
#include "static collision component.hpp"
#include "dynamic collision component.hpp"

using CompList = Utils::TypeList<
  Power,
  Position,
  Movement,
  PlayerAction,
  StaticCollision,
  DynamicCollision
>;

#endif
