local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

assemble([
  e.player({
    pos: [0, 0]
  }),
  e.button({
    pos: [5, 5]
  }),
  a.piston({
    pos: [6, 5],
    dir: "right"
  }),
  e.wire({
    pos: [5, 7],
    sides: ["down", "right"]
  }),
  e.wire({
    pos: [5, 6],
    sides: ["down", "up"]
  }),
  a.piston({
    pos: [6, 7],
    dir: "right"
  })
])
