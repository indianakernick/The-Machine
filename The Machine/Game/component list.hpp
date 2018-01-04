//
//  component list.hpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef component_list_hpp
#define component_list_hpp

#include "movement component.hpp"
#include <Simpleton/Utils/type list.hpp>
#include "static collision component.hpp"
#include "dynamic collision component.hpp"

using CompList = Utils::TypeList<
  Movement,
  StaticCollision,
  DynamicCollision
>;

#endif
