local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "################",
    "#+d+##  ##### e#",
    "#+d+### RRRRR  #",
    "#|#####R####R# #",
    "#d+++#dRRRbR # #",
    "#Bddd  ## #  # #",
    "#     ### #### #",
    "#p             #",
    "################"
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
    "B": e.button
  },

  entities: assemble([
    a.image([0, 0], image, key),
    a.wire_image([0, 0], image),
    e.signal_transmitter({
      pos: [2, 2],
      channel: 0
    }),
    e.signal_transmitter({
      pos: [3, 2],
      channel: 0
    }),
    e.signal_transmitter({
      pos: [4, 2],
      channel: 0
    }),
    e.signal_transmitter({
      pos: [5, 2],
      channel: 0
    }),
    a.piston({
      pos: [9, 2],
      dir: "down"
    }),
    e.delay({
      pos: [2, 3],
      dir: "down",
      length: 2
    }),
    e.delay({
      pos: [3, 3],
      dir: "down",
      length: 2
    }),
    e.wire({
      pos: [4, 3],
      sides: ["up", "right", "down"]
    }),
    e.wire({
      pos: [5, 3],
      sides: ["down", "left"]
    }),
    e.signal_receiver({
      pos: [6, 3],
      channel: 7
    }),
    e.radioactivity_detector({
      pos: [9, 3],
      dir: "up"
    }),
    e.signal_receiver({
      pos: [11, 3],
      channel: 1
    }),
    a.piston({
      pos: [12, 3],
      dir: "up"
    }),
    e.gate({
      pos: [1, 4],
      dir: "right",
      gate: "and"
    }),
    a.piston({
      pos: [6, 4],
      dir: "right"
    }),
    e.gate({
      pos: [2, 6],
      dir: "right",
      gate: "not"
    }),
    a.piston({
      pos: [13, 6],
      dir: "left"
    }),
    e.gate({
      pos: [2, 7],
      dir: "left",
      gate: "not"
    }),
    e.signal_receiver({
      pos: [6, 7],
      channel: 5
    }),
    a.piston({
      pos: [7, 7],
      dir: "down"
    }),
    e.signal_receiver({
      pos: [13, 7],
      channel: 2
    })
  ])
}
