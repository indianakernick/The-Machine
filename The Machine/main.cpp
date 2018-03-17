//
//  main.cpp
//  The Machine
//
//  Created by Indi Kernick on 3/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifdef EMSCRIPTEN
#include "emscripten.h"
#endif
#include "Game/app.hpp"
#include <Simpleton/Utils/profiler.hpp>

static App app;

void mainloop() {
  app.mainloop(16666666);
}

#include <iostream>

int main(int, char **) {
#ifdef EMSCRIPTEN
  emscripten_set_main_loop(mainloop, 0, 0);
  try {
    app.init();
  } catch (std::exception &e) {
    std::cerr << "Exception " << e.what() << '\n';
  }
  emscripten_cancel_main_loop();
  emscripten_set_main_loop(mainloop, 0, 1);
  emscripten_set_main_loop_timing(EM_TIMING_RAF, 0);
#else
  App app;
  app.runMainloop();
#endif
  PROFILER_INFO(stdout);
  return 0;
}
