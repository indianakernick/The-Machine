local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "##  ##  #  H ###",
    " b      #   ##e#",
    " b H##  b      #",
    "  # #        | #",
    "##### ##   # | #",
    "  # # # #  +d+ #",
    "###|#|#|#  d   #",
    "#p B B B       #",
    "################"
  ],

  entities: assemble([
    a.image([0, 0], image, null),
    a.wire_image([0, 0], image),
    a.piston({
      pos: [9, 2],
      dir: "down"
    }),
    a.piston({
      pos: [11, 2],
      dir: "down"
    }),
    a.piston({
      pos: [12, 2],
      dir: "up"
    }),
    e.signal_receiver({
      pos: [13, 2],
      channel: 6
    }),
    e.signal_transmitter({
      pos: [0, 3],
      channel: 7
    }),
    e.signal_receiver({
      pos: [1, 3],
      channel: 6
    }),
    e.signal_transmitter({
      pos: [3, 3],
      channel: 0
    }),
    e.signal_transmitter({
      pos: [5, 3],
      channel: 1
    }),
    e.signal_transmitter({
      pos: [7, 3],
      channel: 2
    }),
    e.gate({
      pos: [9, 3],
      dir: "down",
      gate: "not"
    }),
    e.pressure_plate({
      pos: [12, 3],
      heavy: true
    }),
    e.box({
      pos: [12, 3]
    }),
    a.piston({
      pos: [8, 4],
      dir: "up"
    }),
    e.signal_receiver({
      pos: [9, 4],
      channel: 3
    }),
    e.signal_receiver({
      pos: [0, 5],
      channel: 1
    }),
    a.piston({
      pos: [1, 5],
      dir: "up"
    }),
    e.signal_transmitter({
      pos: [3, 5],
      channel: 3
    }),
    e.signal_receiver({
      pos: [11, 5],
      channel: 7
    }),
    a.piston({
      pos: [12, 5],
      dir: "down"
    }),
    e.signal_receiver({
      pos: [0, 6],
      channel: 0
    }),
    e.radioactivity_detector({
      pos: [11, 6],
      dir: "left"
    }),
    e.gate({
      pos: [12, 6],
      dir: "right",
      gate: "not"
    }),
    a.piston({
      pos: [13, 6],
      dir: "right"
    }),
    a.piston({
      pos: [0, 7],
      dir: "right"
    }),
    e.signal_receiver({
      pos: [4, 7],
      channel: 3
    }),
    a.piston({
      pos: [5, 7],
      dir: "right"
    }),
    e.box({
      pos: [6, 7],
      radioactive: true
    }),
    a.piston({
      pos: [10, 7],
      dir: "left"
    }),
    e.wire({
      pos: [11, 7],
      sides: ["up", "left"]
    }),
    e.signal_receiver({
      pos: [2, 8],
      channel: 2
    }),
    a.piston({
      pos: [3, 8],
      dir: "down"
    }),
    e.signal_receiver({
      pos: [6, 8],
      channel: 2
    }),
    a.piston({
      pos: [7, 8],
      dir: "down"
    }),
    e.signal_receiver({
      pos: [9, 8],
      channel: 4
    }),
    a.piston({
      pos: [10, 8],
      dir: "right"
    }),
    e.box({
      pos: [11, 8]
    })
  ])
}
