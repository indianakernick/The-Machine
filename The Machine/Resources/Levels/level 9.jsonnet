local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "##########  ####",
    "+----   #  H #e#",
    "| b     # b b# #",
    "|  # H H# H  # #",
    "Hb # #d##  bH# #",
    "#  # d+d#    # #",
    "# bH b    H-   #",
    "#p |   d#      #",
    "###+d--+########"
  ],

  local key = {
    "#": e.wall,
    "p": e.player,
    "e": e.exit,
    "b": e.box,
    "H": {
      factory: e.pressure_plate,
      params: {
        heavy: true
      }
    }
  },

  entities: assemble([
    a.image([0, 0], image, key),
    a.wire_image([0, 0], image),
    a.piston({
      pos: [5, 7],
      dir: "down"
    }),
    e.gate({
      pos: [4, 0],
      dir: "right",
      gate: "not"
    }),
    a.piston({
      pos: [5, 3],
      dir: "left"
    }),
    e.gate({
      pos: [6, 5],
      dir: "right",
      gate: "and"
    }),
    e.gate({
      pos: [6, 4],
      dir: "down",
      gate: "not"
    }),
    a.piston({
      pos: [7, 3],
      dir: "down"
    }),
    a.piston({
      pos: [7, 1],
      dir: "up"
    }),
    a.piston({
      pos: [10, 4],
      dir: "down"
    }),
    a.piston({
      pos: [12, 7],
      dir: "down"
    }),
    a.piston({
      pos: [12, 3],
      dir: "left"
    }),
    e.gate({
      pos: [12, 2],
      dir: "right",
      gate: "not"
    }),
    a.piston({
      pos: [13, 2],
      dir: "right"
    })
  ])
}
