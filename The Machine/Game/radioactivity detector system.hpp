//
//  radioactivity detector system.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef radioactivity_detector_system_hpp
#define radioactivity_detector_system_hpp

#include "entity grid.hpp"
#include <Simpleton/ECS/registry.hpp>

// output power if there is a radioactive dynamic entity in front of the detector
void radioactivityDetectorSystem(ECS::Registry &, const EntityGrid &);

#endif
