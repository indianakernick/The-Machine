local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "################",
    "# b -+# --+###e#",
    "# ###db ##|### #",
    "     -- ##|### #",
    "  # ######d-   #",
    "# #      -+### #",
    "#b-  #b####### #",
    "#p             #",
    "################"
  ],

  // using a similar solution for another level will fail
  // try to get the player to make a mistake

  entities: assemble([
    a.image([0, 0], image, null),
    a.wire_image([0, 0], image),
    a.piston({
      pos: [13, 4],
      dir: "right"
    }),
    e.gate({
      pos: [12, 4],
      dir: "right",
      gate: "not"
    }),
    e.gate({
      pos: [10, 4],
      dir: "up",
      gate: "and"
    }),
    e.pressure_plate({
      pos: [8, 3],
      heavy: true
    }),
    e.pressure_plate({
      pos: [7, 7],
      heavy: true
    }),
    a.piston({
      pos: [7, 5],
      dir: "up"
    }),
    e.pressure_plate({
      pos: [4, 5],
      heavy: true
    }),
    a.piston({
      pos: [5, 6],
      dir: "right"
    }),
    e.pressure_plate({
      pos: [3, 7],
      heavy: true
    }),
    e.pressure_plate({
      pos: [1, 2],
      heavy: true
    }),
    e.gate({
      pos: [3, 2],
      dir: "right",
      gate: "not"
    }),
    a.piston({
      pos: [4, 2],
      dir: "down"
    })
  ])
}
