//
//  main.cpp
//  The Machine
//
//  Created by Indi Kernick on 3/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "Game/app.hpp"
#include <Simpleton/SDL/mainloop.hpp>
#include <Simpleton/Utils/profiler.hpp>

int main(int, char **) {
  App app;
  SDL::runMainloop(&app);
  PROFILER_INFO(stdout);
  return 0;
}
