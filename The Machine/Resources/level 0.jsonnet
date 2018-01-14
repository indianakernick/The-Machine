local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

assemble([
  e.player({
    pos: [0, 0]
  }),
  e.exit({
    pos: [31, 17]
  }),
  e.box({
    pos: [2, 2]
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

  e.gate({
    pos: [15, 6],
    gate: "nor",
    dir: "right"
  }),
  e.wire({
    pos: [16, 6],
    sides: ["left", "down"]
  }),
  e.wire({
    pos: [16, 5],
    sides: ["up", "left"]
  }),
  e.wire({
    pos: [15, 5],
    sides: ["right", "up"]
  }),
  a.piston({
    pos: [15, 7],
    dir: "up"
  }),

  e.button({
    pos: [5, 0]
  }),
  e.signal_transmitter({
    pos: [5, 1],
    channel: 5
  }),
  e.signal_receiver({
    pos: [20, 10],
    channel: 5
  }),
  a.piston({
    pos: [20, 9],
    dir: "down"
  }),

  a.piston({
    pos: [10, 1],
    dir: "right"
  }),
  e.box({
    pos: [11, 1],
    radioactive: true
  }),
  a.piston({
    pos: [13, 1],
    dir: "left"
  }),
  e.button({
    pos: [10, 0]
  }),
  e.button({
    pos: [13, 0]
  }),
  e.radioactivity_detector({
    pos: [11, 2],
    dir: "down"
  }),
  e.radioactivity_detector({
    pos: [12, 2],
    dir: "down"
  }),
  a.piston({
    pos: [11, 3],
    dir: "up"
  }),
  a.piston({
    pos: [12, 3],
    dir: "up"
  }),

  e.button({
    pos: [18, 0]
  }),
  e.radioactive_toggle({
    pos: [18, 1],
    dir: "up"
  }),
  e.box({
    pos: [18, 2]
  }),
  e.radioactivity_detector({
    pos: [18, 3],
    dir: "down"
  }),
  a.piston({
    pos: [18, 4],
    dir: "up"
  }),

  e.button({
    pos: [22, 0]
  }),
  e.delay({
    pos: [22, 1],
    dir: "up",
    length: 2
  }),
  e.wire({
    pos: [23, 0],
    sides: ["left", "up"]
  }),
  e.gate({
    pos: [23, 1],
    gate: "not",
    dir: "up"
  }),
  e.wire({
    pos: [23, 2],
    sides: ["up", "down"]
  }),
  e.wire({
    pos: [23, 3],
    sides: ["left", "down"]
  }),
  e.wire({
    pos: [22, 3],
    sides: ["right", "down"]
  }),
  e.gate({
    pos: [22, 2],
    gate: "and",
    dir: "up"
  }),
  e.wire({
    pos: [21, 2],
    sides: ["right", "left"]
  }),
  e.signal_transmitter({
    pos: [20, 2],
    channel: 5
  }),

  e.button({
    pos: [25, 0]
  }),
  e.wire({
    pos: [25, 1],
    sides: ["up", "down", "right"]
  }),
  e.wire({
    pos: [26, 1],
    sides: ["left", "up"]
  }),
  e.wire({
    pos: [26, 2],
    sides: ["down", "up"]
  }),
  e.delay({
    pos: [25, 2],
    length: 2,
    dir: "up"
  }),
  a.piston({
    pos: [25, 3],
    dir: "up"
  }),
  a.piston({
    pos: [26, 3],
    dir: "up"
  }),

  e.button({
    pos: [5, 15]
  }),
  e.wire({
    pos: [6, 15],
    sides: ["left", "up", "right"]
  }),
  e.delay({
    pos: [7, 15],
    dir: "right",
    length: 1
  }),
  e.wire({
    pos: [8, 15],
    sides: ["left", "up", "right"]
  }),
  a.piston({
    pos: [9, 15],
    dir: "right"
  }),
  e.wire({
    pos: [8, 16],
    sides: ["left", "down"]
  }),
  e.wire({
    pos: [7, 16],
    sides: ["left", "right"]
  }),
  e.wire({
    pos: [6, 16],
    sides: ["right", "down"]
  })
])
