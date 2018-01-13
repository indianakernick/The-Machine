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
    pos: [10, 6]
  }),
  e.cross_wire({
    pos: [10, 7]
  }),
  a.piston({
    pos: [10, 8],
    dir: "up"
  }),
  e.lever({
    pos: [9, 7]
  }),
  a.piston({
    pos: [11, 7],
    dir: "right"
  }),

  e.wire({
    pos: [16, 5],
    sides: ["left", "right"]
  }),
  e.wire({
    pos: [15, 5],
    sides: ["up", "right"]
  }),
  e.wire({
    pos: [15, 6],
    sides: ["up", "down", "right"]
  }),
  e.gate({
    pos: [16, 6],
    dir: "left",
    gate: "not"
  }),
  e.wire({
    pos: [17, 6],
    sides: ["left", "down"]
  }),
  e.wire({
    pos: [17, 5],
    sides: ["left", "up"]
  }),
  a.piston({
    pos: [15, 7],
    dir: "up"
  })
])
