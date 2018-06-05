cmake_minimum_required(VERSION 3.10)
project(The_Machine)

set(CMAKE_CXX_STANDARD 17)
set(EMSCRIPTEN_CC /usr/local/Cellar/emscripten/1.37.37/libexec/emcc)
set(CMAKE_CXX_COMPILER ${EMSCRIPTEN_CC})
set(CMAKE_C_COMPILER ${EMSCRIPTEN_CC})
set(RES_PATH /Users/indikernick/Library/Developer/Xcode/DerivedData/The_Machine-blavwwftgvhrjubxbfltzclqnxqi/Build/Products/Release/The\ Machine.app/Contents/Resources)

if (CMAKE_BUILD_TYPE MATCHES RELEASE)
    set(EXTRA_FLAGS "-O3 --closure 1")
else()
    set(EXTRA_FLAGS "-s DEMANGLE_SUPPORT=1")
endif()

set(LINKER_FLAGS " \
  ${EXTRA_FLAGS} \
  -s USE_WEBGL2=1 \
  -s USE_SDL=2 \
  -s TOTAL_MEMORY=805306368 \
  -s DISABLE_EXCEPTION_CATCHING=0 \
  --pre-js '${PROJECT_SOURCE_DIR}/Webpage/init.js' \
  --shell-file '${PROJECT_SOURCE_DIR}/Webpage/index.html' \
  --preload-file '${RES_PATH}@/' \
")
set(CMAKE_CXX_FLAGS " \
  ${EXTRA_FLAGS} \
  -msse3 \
")

include_directories(/usr/local/include/)

set(SOURCE_FILES
        "The Machine/Game/app.cpp"
        "The Machine/Game/button system.cpp"
        "The Machine/Game/clear desired dir system.cpp"
        "The Machine/Game/clear player input system.cpp"
        "The Machine/Game/clear real dir system.cpp"
        "The Machine/Game/cross wire sprite writer.cpp"
        "The Machine/Game/delay system.cpp"
        "The Machine/Game/device input system.cpp"
        "The Machine/Game/entity grid.cpp"
        "The Machine/Game/exit system.cpp"
        "The Machine/Game/game level.cpp"
        "The Machine/Game/game logic.cpp"
        "The Machine/Game/game screen.cpp"
        "The Machine/Game/game tick.cpp"
        "The Machine/Game/game view.cpp"
        "The Machine/Game/gate system.cpp"
        "The Machine/Game/init grid system.cpp"
        "The Machine/Game/level controller.cpp"
        "The Machine/Game/level transition.cpp"
        "The Machine/Game/lever system.cpp"
        "The Machine/Game/move dir system.cpp"
        "The Machine/Game/music player.cpp"
        "The Machine/Game/piston system.cpp"
        "The Machine/Game/player input response system.cpp"
        "The Machine/Game/player input system.cpp"
        "The Machine/Game/power input system.cpp"
        "The Machine/Game/power sprite writer.cpp"
        "The Machine/Game/pressure plate system.cpp"
        "The Machine/Game/quad writer.cpp"
        "The Machine/Game/radioactive toggle system.cpp"
        "The Machine/Game/radioactivity detector system.cpp"
        "The Machine/Game/radioactivity sprite writer.cpp"
        "The Machine/Game/rendering helpers.cpp"
        "The Machine/Game/rendering system.cpp"
        "The Machine/Game/screen manager.cpp"
        "The Machine/Game/screen.cpp"
        "The Machine/Game/shift cross wire system.cpp"
        "The Machine/Game/shift player action system.cpp"
        "The Machine/Game/shift power system.cpp"
        "The Machine/Game/shift radioactivity system.cpp"
        "The Machine/Game/signal channel toggle system.cpp"
        "The Machine/Game/signal receiver system.cpp"
        "The Machine/Game/sprite position system.cpp"
        "The Machine/Game/static sprite writer.cpp"
        "The Machine/Game/title screen writer.cpp"
        "The Machine/Game/title screen.cpp"
        "The Machine/Game/transition writer.cpp"
        "The Machine/Game/update pos system.cpp"
        "The Machine/Game/wire system.cpp"
        "The Machine/main.cpp")

add_executable(The_Machine ${SOURCE_FILES})
set_target_properties(The_Machine PROPERTIES OUTPUT_NAME index.html)
set_target_properties(The_Machine PROPERTIES LINK_FLAGS "${LINKER_FLAGS} -s WASM=1")