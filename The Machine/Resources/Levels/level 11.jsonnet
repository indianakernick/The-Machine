local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "################",
    "#+------- ####e#",
    "#+d  bbbbb -+# #",
    "#|##bb bb  #d# #",
    "#|##d#####d#+d #",
    "#B--+-----+### #",
    "# ############ #",
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
      pos: [12, 5],
      dir: "down",
      gate: "not"
    }),
    e.radioactivity_detector({
      pos: [10, 6],
      dir: "left"
    }),
    a.piston({
      pos: [10, 5],
      dir: "left"
    }),
    e.delay({
     pos: [10, 4],
     dir: "up",
     length: 2
    }),
    a.piston({
      pos: [9, 7],
      dir: "down"
    }),
    e.box({
      pos: [6, 5],
      radioactive: true
    }),
    a.piston({
      pos: [4, 4],
      dir: "up"
    }),
    a.piston({
      pos: [3, 6],
      dir: "right"
    }),
    e.delay({
      pos: [2, 6],
      dir: "right",
      length: 2
    })
  ])
}
