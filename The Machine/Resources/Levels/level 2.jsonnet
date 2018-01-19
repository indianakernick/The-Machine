local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  "meta": {
    "size": [16, 9]
  },
  "entities": assemble([
    e.player({
      pos: [1, 1]
    }),
    e.exit({
      pos: [14, 7]
    }),
    a.rectangle([0, 0], [16, 1], function(position)
      e.wall({pos: position})
    ),
    e.wall({
      pos: [0, 1]
    }),
    a.rectangle([0, 2], [7, 7], function(position)
      e.wall({pos: position})
    ),
    a.rectangle([8, 8], [8, 1], function(position)
      e.wall({pos: position})
    ),
    e.wall({
      pos: [15, 7]
    }),
    a.rectangle([9, 1], [7, 1], function(position)
      e.wall({pos: position})
    ),
    a.rectangle([8, 2], [8, 5], function(position)
      e.wall({pos: position})
    ),
    e.box({
      pos: [7, 1]
    }),
    e.box({
      pos: [7, 7]
    }),
  ])
}
