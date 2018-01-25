#introduction to signals

local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "################",
    "# # # # # # ##e#",
    "#T#T#T#T#T#T+d #",
    "#b#B#b#b#B#b|# #",
    "#D#D#D#D#D#Dd#p#",
    "#            # #",
    "##          #  #",
    "#############  #",
    "################"
  ],

  local key = {
    "#": e.wall,
    "p": e.player,
    "e": e.exit,
    "b": e.box,
    "B": {
      factory: e.box,
      params: {
        radioactive: true
      }
    },
    "l": e.lever,
    "T": {
      factory: e.radioactive_toggle,
      params: {
        dir: "down"
      }
    },
    "D": {
      factory: e.radioactivity_detector,
      params: {
        dir: "up"
      }
    }
  },

  entities: assemble([
    a.image([0, 0], image, key),
    a.wire_image([0, 0], image),

    [
      e.signal_receiver({
        pos: [2 * i + 1, 7],
        channel: i
      })
      for i in std.makeArray(6, function(i)i)
    ],

    [
      local left = 2 * i + 2;
      local right = 2 * i + 3;
      local up = 3;
      local down = 2;
      [
        e.wire({
          pos: [left, up],
          sides: ["down", "left"]
        }),
        e.gate({
          pos: [right, up],
          dir: "right",
          gate: "and"
        }),
        e.wire({
          pos: [left, down],
          sides: ["up", "right"]
        }),
        e.wire({
          pos: [right, down],
          sides: ["up", "left"]
        })
      ] for i in std.makeArray(5, function(i)i)
    ],

    e.wire({
      pos: [1, 3],
      sides: ["up", "right"]
    }),
    e.wire({
      pos: [12, 3],
      sides: ["up", "left"]
    }),
    e.gate({
      pos: [12, 4],
      dir: "up",
      gate: "not"
    }),
    a.piston({
      pos: [13, 6],
      dir: "right"
    }),
    e.signal_transmitter({
      pos: [13, 1],
      channel: 0
    }),
    e.button({
      pos: [14, 1]
    })
  ])
}
