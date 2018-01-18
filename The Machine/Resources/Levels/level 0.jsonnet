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
    a.rectangle([0, 8], [16, 1], function(position)
      e.wall({pos: position})
    ),
    a.rectangle([0, 1], [1, 7], function(position)
      e.wall({pos: position})
    ),
    a.rectangle([15, 1], [1, 7], function(position)
      e.wall({pos: position})
    )
  ])
}
