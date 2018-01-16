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
  size_t countQuads();
  virtual void writeQuads(QuadIter, Frame) const = 0;
  virtual TextureID getTexture() const = 0;

private:
  size_t quadCount = 0;

  virtual size_t count() const = 0;
};

#endif
