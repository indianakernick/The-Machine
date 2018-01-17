//
//  shift cross wire system.hpp
//  The Machine
//
//  Created by Indi Kernick on 10/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef shift_cross_wire_system_hpp
#define shift_cross_wire_system_hpp

#include <Simpleton/ECS/registry.hpp>

//Shift the Power components held by the CrossWire component as described in the
//shiftPowerSystem
void shiftCrossWireSystem(ECS::Registry &);

#endif
