local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "################",
    "#######e      ##",
    "#############  #",
    "############# |#",
    "##+------+d+#  #",
    "##d######d#d# |#",
    "# b    p      H#",
    "#   ############",
    "################"
  ],

  entities: assemble([
    a.image([0, 0], image, null),
    a.wire_image([0, 0], image),
    a.piston({
      pos: [2, 3],
      dir: "down"
    }),
    e.lever({
      pos: [9, 3]
    }),
    e.gate({
      pos: [10, 4],
      dir: "right",
      gate: "not"
    }),
    a.piston({
      pos: [11, 3],
      dir: "down"
    }),
    e.gate({
      pos: [14, 4],
      dir: "up",
      gate: "not"
    }),
    a.piston({
      pos: [14, 6],
      dir: "left"
    })
  ])
}

