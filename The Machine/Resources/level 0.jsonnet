local e = import "entities.libsonnet";
local common = import "common.libsonnet";

[
  e.box({
    pos: [0, 0]
  }),
  e.radioactive_toggle({
    pos: [0, 1],
    dir: "down"
  }),
  e.air({
    pos: [0, 0]
  }),
  e.button({
    pos: [1, 1]
  }),
  e.air({
    pos: [1, 2]
  }),
  e.air({
    pos: [2, 1]
  }),
  e.gate({
    pos: [1, 0],
    gate: "xor"
  }),
  e.exit({
    pos: [2, 0]
  }),
  e.lever({
    pos: [3, 0]
  }),
  e.player({
    pos: [3, 1]
  }),
  e.air({
    pos: [3, 1]
  }),
  e.piston_base({
    pos: [4, 0],
    dir: "right"
  }),
  e.piston_head({
    pos: [4, 0],
    dir: "right"
  }),
  e.air({
    pos: [5, 0]
  }),
  e.pressure_plate({
    pos: [5, 1],
    heavy: false
  }),
  e.air({
    pos: [4, 1]
  }),
  e.air({
    pos: [5, 2]
  }),
  e.air({
    pos: [6, 1]
  }),
  e.box({
    pos: [10, 12],
    radioactive: true
  }),
  e.radioactivity_detector({
    pos: [9, 10],
    dir: "right"
  }),
  e.air({
    pos: [10, 10]
  })
]
