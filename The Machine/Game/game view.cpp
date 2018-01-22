//
//  game view.cpp
//  The Machine
//
//  Created by Indi Kernick on 22/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#include "game view.hpp"

#include <Simpleton/SDL/paths.hpp>
#include "power sprite writer.hpp"
#include "static sprite writer.hpp"
#include "sprite position system.hpp"
#include "cross wire sprite writer.hpp"
#include "radioactivity sprite writer.hpp"
#include <Simpleton/Camera 2D/zoom to fit.hpp>

void GameView::init(RenderingSystem &rendering, std::shared_ptr<ECS::Registry> registry) {
  camera.transform.setOrigin(Cam2D::Origin::CENTER);
  camera.targetZoom = std::make_unique<Cam2D::ZoomToFit>(glm::vec2());
  
  const TextureID tex = rendering.addTexture("sprites.png");
  const std::string atlasPath = SDL::getResDir() + "sprites.atlas";
  sheet = std::make_shared<Spritesheet>(Unpack::makeSpritesheet(atlasPath));
  
  writers.push_back(rendering.addWriter<PowerSpriteWriter>(tex, registry, sheet));
  writers.push_back(rendering.addWriter<StaticSpriteWriter>(tex, registry, sheet));
  writers.push_back(rendering.addWriter<CrossWireSpriteWriter>(tex, registry, sheet));
  writers.push_back(rendering.addWriter<RadioactivitySpriteWriter>(tex, registry, sheet));
}

void GameView::quit() {
  sheet.reset();
}

void GameView::onLevelLoad(const Pos levelSize) {
  camera.setPos(static_cast<glm::vec2>(levelSize) / 2.0f);
  dynamic_cast<Cam2D::ZoomToFit *>(camera.targetZoom.get())->setSize(levelSize);
}

void GameView::updateCam(const float aspect, const float delta) {
  camera.update(aspect, delta);
}

void GameView::render(RenderingSystem &rendering, ECS::Registry &registry, const Frame frame) {
  spritePositionSystem(registry, frame);
  rendering.render(writers, camera.transform.toPixels(), frame);
}
