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
  }),

  e.lever({
    pos: [10, 5]
  }),
  e.wire({
    pos: [10, 6],
    sides: ["down", "up"]
  }),
  e.cross_wire({
    pos: [10, 7]
  }),
  e.wire({
    pos: [10, 8],
    sides: ["down", "up"]
  }),
  a.piston({
    pos: [10, 9],
    dir: "up"
  }),
  e.lever({
    pos: [8, 7]
  }),
  e.wire({
    pos: [9, 7],
    sides: ["left", "right"]
  }),
  e.wire({
    pos: [11, 7],
    sides: ["left", "right"]
  }),
  a.piston({
    pos: [12, 7],
    dir: "right"
  })
])
