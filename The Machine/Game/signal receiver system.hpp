//
//  signal receiver system.hpp
//  The Machine
//
//  Created by Indi Kernick on 6/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef signal_receiver_system_hpp
#define signal_receiver_system_hpp

#include <entt/entity/registry.hpp>

// sets the power output of a receiver based on the power input and a
// transmitter on the same channel
void signalReceiverSystem(entt::registry &);

#endif
