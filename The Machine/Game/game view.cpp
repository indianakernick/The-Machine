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

void GameView::init(RenderingSystem &rendering, std::shared_ptr<entt::registry> registry) {
  camera.transform.setOrigin(Cam2D::Origin::CENTER);
  
  const TextureID tex = rendering.addTexture("sprites.png");
  const std::string atlasPath = SDL::getResDir() + "sprites.atlas";
  sheet = std::make_shared<Sheet>(Sprite::makeSheetFromFile(atlasPath));
  
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
  zoomToFit.setSize(levelSize);
}

void GameView::updateCam(const float aspect, const float delta) {
  camera.update({aspect, delta}, zoomToFit);
}

void GameView::render(RenderingSystem &rendering, entt::registry &registry, const Frame frame) {
  spritePositionSystem(registry, frame);
  rendering.render(writers, camera.transform.toPixels(), frame);
}
