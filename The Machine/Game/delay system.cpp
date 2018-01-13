//
//  delay system.cpp
//  The Machine
//
//  Created by Indi Kernick on 13/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "delay system.hpp"

#include "delay component.hpp"
#include "power component.hpp"
#include "power input component.hpp"

void delaySystem(ECS::Registry &registry) {
  auto view = registry.view<Delay, Power, PowerInput>();
  
  for (const ECS::EntityID entity : view) {
    Delay &delay = view.get<Delay>(entity);
    const bool input = Math::any(view.get<PowerInput>(entity).states);
    bool output = false;
    
    if (delay.state == Delay::State::LOW) {
      if (input) {
        delay.state = Delay::State::RISE;
      }
    }
    
    if (delay.state == Delay::State::RISE) {
      ++delay.counter;
      if (delay.counter == delay.length) {
        if (input) {
          delay.state = Delay::State::HIGH;
        } else {
          delay.state = Delay::State::FALL;
          ++delay.counter;
        }
      }
    }
    
    if (delay.state == Delay::State::HIGH) {
      output = true;
      if (!input) {
        delay.state = Delay::State::FALL;
      }
    }
    
    if (delay.state == Delay::State::FALL) {
      --delay.counter;
      if (delay.counter == 0) {
        if (input) {
          delay.state = Delay::State::RISE;
        } else {
          delay.state = Delay::State::LOW;
        }
        output = false;
      } else {
        output = true;
      }
    }
    
    view.get<Power>(entity).curr = output;
  }
}
