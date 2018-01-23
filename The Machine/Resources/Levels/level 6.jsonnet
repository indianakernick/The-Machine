local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "################",
    "##############e#",
    "############## #",
    "#l-----+###### #",
    "# #####d-- --  #",
    "#l-----+###### #",
    "# ############ #",
    "#p             #",
    "################"
  ],

  entities: assemble([
    a.image([0, 0], image, null),
    a.wire_image([0, 0], image),
    e.gate({
      pos: [7, 4],
      dir: "right",
      gate: "and"
    }),
    e.gate({
      pos: [10, 4],
      dir: "right",
      gate: "not"
    }),
    a.piston({
      pos: [13, 4],
      dir: "right"
    })
  ])
}
