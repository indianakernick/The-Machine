//
//  quad writer.hpp
//  The Machine
//
//  Created by Indi Kernick on 7/1/18.
//  Copyright © 2018 Indi Kernick. All rights reserved.
//

#ifndef quad_writer_hpp
#define quad_writer_hpp

#include "frame type.hpp"
#include "position type.hpp"
#include "rendering types.hpp"
#include <Simpleton/Math/dir.hpp>
#include <Simpleton/ECS/registry.hpp>
#include "sprite position component.hpp"

class QuadWriter {
public:
  QuadWriter() = default;
  virtual ~QuadWriter() = default;
  
  size_t numQuads() const;
  size_t countQuads(ECS::Registry &);
  virtual void writeQuads(QuadIter, ECS::Registry &, const Spritesheet &, Frame) const = 0;

private:
  size_t quadCount = 0;

  virtual size_t count(ECS::Registry &) const = 0;

protected:
  static void writePos(QuadIter, SpritePosition);
  static void writeTexCoords(QuadIter, const Spritesheet &, SpriteID);
};

#endif
