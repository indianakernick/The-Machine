//
//  signal receiver init.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef signal_receiver_init_hpp
#define signal_receiver_init_hpp

#include <Simpleton/ECS/comp init.hpp>
#include "signal receiver component.hpp"

class SignalReceiverInit final : public ECS::CompInit<SignalReceiver> {
public:
  void init(SignalReceiver &, const json &) override;
};

#endif
