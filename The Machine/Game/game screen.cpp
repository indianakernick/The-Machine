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
#include "rendering system.hpp"
#include <Simpleton/SDL/paths.hpp>
#include <Simpleton/SDL/events.hpp>
#include <Simpleton/Utils/profiler.hpp>
#include <Simpleton/Camera 2D/zoom to fit.hpp>

void GameScreen::init(std::shared_ptr<RenderingSystem> renderingSystem) {
  PROFILE(GameScreen::init);

  rendering = renderingSystem;
  
  const TextureID tex = rendering->addTexture("sprites.png");
  const std::string atlasPath = SDL::getResDir() + "sprites.atlas";
  sheet = std::make_shared<Spritesheet>(Unpack::makeSpritesheet(atlasPath));
  registry = std::make_shared<ECS::Registry>();
  
  quadWriters.push_back(rendering->addWriter<PowerSpriteWriter>(tex, registry, sheet));
  quadWriters.push_back(rendering->addWriter<StaticSpriteWriter>(tex, registry, sheet));
  quadWriters.push_back(rendering->addWriter<CrossWireSpriteWriter>(tex, registry, sheet));
  quadWriters.push_back(rendering->addWriter<RadioactivitySpriteWriter>(tex, registry, sheet));

  camera.transform.setOrigin(Cam2D::Origin::CENTER);
  camera.targetZoom = std::make_unique<Cam2D::ZoomToFit>(glm::vec2());
  
  progress.setFilePath(SDL::getSaveDir("Indi Kernick", "The Machine") + "progress.txt");
  progress.readFile();
  levels.setPath(SDL::getResDir() + "level ");
  
  loadLevel(progress.getIncompleteLevel());
}

void GameScreen::quit() {
  PROFILE(GameScreen::quit);
  
  registry.reset();
  sheet.reset();
  rendering.reset();
}

void GameScreen::enter() {
  rendering->updateQuadCount();
}

void GameScreen::input(const SDL_Event &e) {
  const auto newLevel = levelControl.getLevel(
    e,
    levels.current(),
    progress.getIncompleteLevel()
  );
  if (newLevel) {
    loadLevel(*newLevel);
  }
  
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
  
  signalChannelToggleSystem(*registry, grid);
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
  
  if (exitSystem(*registry, grid)) {
    const ECS::Level current = levels.current();
    if (current != ECS::NULL_LEVEL) {
      progress.finishLevel(current);
      loadLevel(current + 1);
    }
  }
}

void GameScreen::render(const float aspect, const float delta) {
  PROFILE(GameScreen::render);
  
  spritePositionSystem(*registry, frame);
  camera.update(aspect, delta);
  rendering->render(quadWriters, camera.transform.toPixels(), frame);
}

bool GameScreen::loadLevel(const ECS::Level level) {
  PROFILE(GameScreen::loadLevel);

  const OptionalObject meta = levels.load(*registry, level);
  if (meta) {
    const Pos levelSize = meta->at("size").get<Pos>();
    camera.setPos(static_cast<glm::vec2>(levelSize) / 2.0f);
    dynamic_cast<Cam2D::ZoomToFit *>(camera.targetZoom.get())->setSize(levelSize);
    grid = EntityGrid(levelSize);
    initGridSystem(*registry, grid);
  }
  rendering->updateQuadCount();
  return static_cast<bool>(meta);
}
