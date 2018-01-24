local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "+-----------d   ",
    "+d         #|   ",
    "|#     b   ++++#",
    "| b #d d   d d|#",
    "|  #++-+ |    |#",
    "+-l-+d#d |    ++",
    "#        |deb d|",
    "# bb#HdH#|+d   |",
    "#p  ##+d-+## --+"
  ],

  entities: assemble([
    a.image([0, 0], image, null),
    a.wire_image([0, 0], image),
    e.gate({
      pos: [12, 8],
      dir: "up",
      gate: "and"
    }),
    e.wire({
      pos: [13, 8],
      sides: ["right", "down", "left"]
    }),
    e.gate({
      pos: [14, 8],
      dir: "left",
      gate: "not"
    }),
    e.wire({
      pos: [15, 8],
      sides: ["down", "left"]
    }),
    a.piston({
      pos: [1, 7],
      dir: "right"
    }),
    e.radioactivity_detector({
      pos: [8, 7],
      dir: "left"
    }),
    e.gate({
      pos: [9, 7],
      dir: "right",
      gate: "not"
    }),
    a.piston({
      pos: [10, 7],
      dir: "down"
    }),
    e.wire({
      pos: [13, 7],
      sides: ["up", "right"]
    }),
    e.gate({
      pos: [14, 7],
      dir: "right",
      gate: "not"
    }),
    e.wire({
      pos: [15, 7],
      sides: ["up", "left"]
    }),
    e.box({
      pos: [2, 6],
      radioactive: true
    }),
    a.piston({
      pos: [5, 6],
      dir: "up"
    }),
    e.gate({
      pos: [5, 5],
      dir: "up",
      gate: "not"
    }),
    a.piston({
      pos: [7, 5],
      dir: "up"
    }),
    a.piston({
      pos: [9, 5],
      dir: "up"
    }),
    e.delay({
      pos: [11, 5],
      dir: "down",
      length: 2
    }),
    a.piston({
      pos: [13, 5],
      dir: "down"
    }),
    a.piston({
      pos: [11, 4],
      dir: "right"
    }),
    e.box({
      pos: [13, 4],
      radioactive: true
    }),
    a.piston({
      pos: [5, 3],
      dir: "down"
    }),
    a.piston({
      pos: [7, 3],
      dir: "down"
    }),
    e.box({
      pos: [12, 3],
      radioactive: true
    }),
    e.box({
      pos: [13, 3],
      radioactive: true
    }),
    a.piston({
      pos: [10, 2],
      dir: "up"
    }),
    e.box({
      pos: [13, 2],
      radioactive: true
    }),
    e.delay({
      pos: [14, 2],
      dir: "down",
      length: 2
    }),
    e.gate({
      pos: [6, 1],
      dir: "up",
      gate: "and"
    }),
    e.radioactivity_detector({
      pos: [11, 1],
      dir: "right"
    }),
    e.box({
      pos: [12, 1],
      radioactive: true
    }),
    a.piston({
      pos: [14, 1],
      dir: "left"
    }),
    e.gate({
      pos: [7, 0],
      dir: "right",
      gate: "not"
    }),
    a.piston({
      pos: [12, 0],
      dir: "up"
    })
  ])
}
