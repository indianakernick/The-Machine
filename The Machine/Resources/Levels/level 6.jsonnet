local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "################",
    "#     d+#+-+##e#",
    "# # # #|#|#|## #",
    "#  #  #|#|#|## #",
    "# b # #|#|#+-d #",
    "#     #+-+#### #",
    "# ############ #",
    "#p             #",
    "################"
  ],

  entities: assemble([
    a.image([0, 0], image, null),
    a.wire_image([0, 0], image),
    e.pressure_plate({
      pos: [6, 7],
      heavy: false
    }),
    a.piston({
      pos: [13, 4],
      dir: "right"
    })
  ])
}

