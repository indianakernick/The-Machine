local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  "meta": {
    "size": [16, 9]
  },

  local image = [
    "################",
    "#+-+#+-+#+-+##e#",
    "#|#|#|#|#|#|## #",
    "#|#|#|#|#|#|## #",
    "#|#|#|#|#|#+-db ",
    "#|#+-+#+-+#### #",
    "#d############ #",
    "#p             #",
    "################"
  ],

  // wire image assembly

  local key = {
    "#": e.wall,
    "p": e.player,
    "e": e.exit,
    "b": e.box
  },

  "entities": assemble([
    a.image([0, 0], image, key),
    a.wire_image([0, 0], image),
    e.lever({
      pos: [1, 2]
    }),
    a.piston({
      pos: [13, 4],
      dir: "right"
    })
  ])
}
