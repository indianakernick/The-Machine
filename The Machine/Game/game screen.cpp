//
//  game screen.cpp
//  The Machine
//
//  Created by Indi Kernick on 4/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "game screen.hpp"

#include "systems.hpp"
#include "quad writers.hpp"
#include "component inits.hpp"
#include <Simpleton/SDL/paths.hpp>
#include <Simpleton/Utils/profiler.hpp>
#include <Simpleton/Camera 2D/zoom to fit.hpp>

void GameScreen::init() {
  PROFILE(GameScreen::init);

  rendering.init();
  
  const TextureID tex = rendering.addTexture("sprites.png");
  const std::string atlasPath = SDL::getResDir() + "sprites.atlas";
  sheet = std::make_shared<Spritesheet>(Unpack::makeSpritesheet(atlasPath));
  registry = std::make_shared<ECS::Registry>();
  
  quadWriters.push_back(rendering.addWriter<PowerSpriteWriter>(tex, registry, sheet));
  quadWriters.push_back(rendering.addWriter<StaticSpriteWriter>(tex, registry, sheet));
  quadWriters.push_back(rendering.addWriter<CrossWireSpriteWriter>(tex, registry, sheet));
  quadWriters.push_back(rendering.addWriter<RadioactivitySpriteWriter>(tex, registry, sheet));

  camera.transform.setOrigin(Cam2D::Origin::CENTER);
  camera.targetZoom = std::make_unique<Cam2D::ZoomToFit>(glm::vec2());

  compInits.construct<GateInit>();
  compInits.construct<WireInit>();
  compInits.construct<DelayInit>();
  compInits.construct<PistonInit>();
  compInits.construct<WeightInit>();
  compInits.construct<PositionInit>();
  compInits.construct<PowerInputInit>();
  compInits.construct<PowerSpriteInit>();
  compInits.construct<PowerOutputInit>();
  compInits.construct<StaticSpriteInit>();
  compInits.construct<RadioactivityInit>();
  compInits.construct<PressurePlateInit>();
  compInits.construct<SpritePositionInit>();
  compInits.construct<SignalReceiverInit>();
  compInits.construct<StaticCollisionInit>();
  compInits.construct<CrossWireSpriteInit>();
  compInits.construct<DynamicCollisionInit>();
  compInits.construct<SignalTransmitterInit>();
  compInits.construct<RadioactiveToggleInit>();
  compInits.construct<RadioactivitySpriteInit>();
  compInits.construct<RadioactivityDetectorInit>();
  compInits.constructDefaults();

  progress.setFilePath(SDL::getSaveDir("Indi Kernick", "The Machine") + "progress.txt");
  progress.readFile();
  levels.init(*registry, compInits);
  levels.levelPath([] (const ECS::Level level) {
    const std::string levelStr = level == ECS::FINAL_LEVEL ? "final" : std::to_string(level);
    return SDL::getResDir() + "level " + levelStr + ".json";
  });
  
  loadLevel(progress.getIncompleteLevel());
}

void GameScreen::quit() {
  PROFILE(GameScreen::quit);
  
  registry.reset();
  sheet.reset();
  levels.quit();
  compInits.destroyAll();
  rendering.quit();
}

void GameScreen::enter() {
  rendering.updateQuadCount();
}

void GameScreen::input(const SDL_Event &e) {
  playerInputSystem(playerInput, e);
}

void GameScreen::update(float) {
  PROFILE(GameScreen::update);
  
  if (frame == FRAMES_PER_TICK - 1) {
    frame = 0;
  } else {
    ++frame;
    return;
  }

  shiftPowerSystem(*registry);
  shiftCrossWireSystem(*registry);
  shiftPlayerActionSystem(*registry);
  shiftRadioactivitySystem(*registry);
  
  playerInputResponseSystem(*registry, playerInput);
  clearPlayerInputSystem(playerInput);
  
  updatePosSystem(*registry, grid);
  
  radioactivityDetectorSystem(*registry, grid);
  signalReceiverSystem(*registry);
  pressurePlateSystem(*registry, grid);
  leverSystem(*registry, grid);
  buttonSystem(*registry, grid);
  
  powerInputSystem(*registry, grid);
  gateSystem(*registry);
  delaySystem(*registry);
  wireSystem(*registry, grid);
  deviceInputSystem(*registry);
  
  radioactiveToggleSystem(*registry, grid);
  pistonSystem(*registry, grid);
  
  clearRealDirSystem(*registry);
  moveDirSystem(*registry, grid);
  clearDesiredDirSystem(*registry);
}

void GameScreen::render(const float aspect, const float delta) {
  PROFILE(GameScreen::render);
  
  spritePositionSystem(*registry, frame);
  camera.update(aspect, delta);
  rendering.render(quadWriters, camera.transform.toPixels(), frame);
}

bool GameScreen::loadLevel(const ECS::Level level) {
  PROFILE(GameScreen::loadLevel);

  const bool success = levels.loadLevel(level);
  // @TODO level size should be defined in level file
  constexpr Pos LEVEL_SIZE = {32, 18};
  camera.setPos(LEVEL_SIZE / 2u);
  dynamic_cast<Cam2D::ZoomToFit *>(camera.targetZoom.get())->setSize(LEVEL_SIZE);
  grid = EntityGrid(LEVEL_SIZE);
  initGridSystem(*registry, grid);
  rendering.updateQuadCount();
  return success;
}
