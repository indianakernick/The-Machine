//
//  shift radioactivity system.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef shift_radioactivity_system_hpp
#define shift_radioactivity_system_hpp

#include <Simpleton/ECS/registry.hpp>

// set Radioactivity::prev to Radioactivity::curr
void shiftRadioactivitySystem(ECS::Registry &);

#endif
