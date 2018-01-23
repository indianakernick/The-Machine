local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "################",
    "####+-+-+--+##e#",
    "####d#d#d##|## #",
    "####|#|#|##|## #",
    "###+d+d+d+#+-  #",
    "###|#|#|#|#### #",
    "###l#l#l#l#### #",
    "#p             #",
    "################"
  ],

  entities: assemble([
    a.image([0, 0], image, null),
    a.wire_image([0, 0], image),
    a.piston({
      pos: [13, 4],
      dir: "right"
    }),
    e.gate({
      pos: [4, 4],
      dir: "right",
      gate: "and"
    }),
    e.gate({
      pos: [6, 4],
      dir: "right",
      gate: "xor"
    }),
    e.gate({
      pos: [8, 4],
      dir: "right",
      gate: "or"
    }),
    e.gate({
      pos: [4, 6],
      dir: "up",
      gate: "not"
    }),
    e.gate({
      pos: [6, 6],
      dir: "up",
      gate: "not"
    }),
    e.gate({
      pos: [8, 6],
      dir: "up",
      gate: "not"
    }),
  ])
}
