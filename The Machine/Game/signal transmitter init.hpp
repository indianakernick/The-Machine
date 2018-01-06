//
//  signal transmitter init.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef signal_transmitter_init_hpp
#define signal_transmitter_init_hpp

#include <Simpleton/ECS/comp init.hpp>
#include "signal transmitter component.hpp"

class SignalTransmitterInit final : public ECS::CompInit<SignalTransmitter> {
public:
  void init(SignalTransmitter &, const json &) override;
};

#endif
