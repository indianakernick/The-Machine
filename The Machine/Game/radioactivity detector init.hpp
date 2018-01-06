//
//  radioactivity detector init.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef radioactivity_detector_init_hpp
#define radioactivity_detector_init_hpp

#include <Simpleton/ECS/comp init.hpp>
#include "radioactivity detector component.hpp"

class RadioactivityDetectorInit final : public ECS::CompInit<RadioactivityDetector> {
public:
  void init(RadioactivityDetector &, const json &) override;
};

#endif
