local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "### H####    ###",
    "###     # # ##e#",
    "b      RRbR  # #",
    "  bb  R RRRR # #",
    "      # #      #",
    "##  R      # # #",
    "##### ###### # #",
    "#pB  b         #",
    "##### ##########"
  ],

  local key = {
    "#": e.wall,
    "p": e.player,
    "e": e.exit,
    "b": e.box,
    "R": {
      factory: e.box,
      params: {
        radioactive: true
      }
    },
    "H": {
      factory: e.pressure_plate,
      params: {
        heavy: true
      }
    },
    "B": e.button
  },

  entities: assemble([
    a.image([0, 0], image, key),
    e.signal_transmitter({
      pos: [3, 1],
      channel: 0
    }),
    a.piston({
      pos: [5, 2],
      dir: "down"
    }),
    a.piston({
      pos: [12, 2],
      dir: "down"
    }),
    e.signal_receiver({
      pos: [2, 3],
      channel: 3
    }),
    e.radioactive_toggle({
      pos: [3, 3],
      dir: "right"
    }),
    e.signal_receiver({
      pos: [5, 3],
      channel: 0
    }),
    e.signal_receiver({
      pos: [6, 3],
      channel: 6
    }),
    e.gate({
      pos: [7, 3],
      dir: "up",
      gate: "and"
    }),
    e.signal_receiver({
      pos: [8, 3],
      channel: 2
    }),
    e.signal_transmitter({
      pos: [10, 3],
      channel: 7
    }),
    e.signal_receiver({
      pos: [12, 3],
      channel: 7
    }),
    e.signal_receiver({
      pos: [0, 4],
      channel: 1
    }),
    e.signal_receiver({
      pos: [1, 4],
      channel: 2
    }),
    e.signal_receiver({
      pos: [2, 4],
      channel: 4
    }),
    a.piston({
      pos: [3, 4],
      dir: "up"
    }),
    e.radioactivity_detector({
      pos: [4, 4],
      dir: "down"
    }),
    e.signal_receiver({
      pos: [5, 4],
      channel: 5
    }),
    a.piston({
      pos: [7, 4],
      dir: "up"
    }),
    e.radioactivity_detector({
      pos: [10, 4],
      dir: "up"
    }),
    e.signal_receiver({
      pos: [11, 4],
      channel: 3
    }),
    e.gate({
      pos: [12, 4],
      dir: "up",
      gate: "and"
    }),
    e.signal_receiver({
      pos: [13, 4],
      channel: 6
    }),
    e.radioactive_toggle({
      pos: [0, 5],
      dir: "up"
    }),
    a.piston({
      pos: [1, 5],
      dir: "right"
    }),
    a.piston({
      pos: [4, 5],
      dir: "up"
    }),
    a.piston({
      pos: [5, 5],
      dir: "right"
    }),
    a.piston({
      pos: [12, 5],
      dir: "left"
    }),
    e.radioactivity_detector({
      pos: [1, 6],
      dir: "left"
    }),
    a.piston({
      pos: [2, 6],
      dir: "right"
    }),
    a.piston({
      pos: [6, 6],
      dir: "right"
    }),
    e.signal_receiver({
      pos: [5, 7],
      channel: 6
    }),
    e.gate({
      pos: [6, 7],
      dir: "up",
      gate: "and"
    }),
    e.signal_receiver({
      pos: [7, 7],
      channel: 1
    }),
    a.piston({
      pos: [9, 7],
      dir: "down"
    }),
    a.piston({
      pos: [11, 7],
      dir: "down"
    }),
    e.signal_transmitter({
      pos: [3, 8],
      channel: 6
    }),
    e.signal_receiver({
      pos: [9, 8],
      channel: 5
    }),
    e.signal_receiver({
      pos: [10, 8],
      channel: 6
    }),
    e.gate({
      pos: [11, 8],
      dir: "up",
      gate: "and"
    }),
    e.signal_receiver({
      pos: [12, 8],
      channel: 0
    })
  ])
}
