local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  "meta": {
    "size": [16, 9]
  },

  local image = [
    "################",
    "# - # - # - ##e#",
    "#|#|#|#|#|#|## #",
    "#|#|#|#|#|#|## #",
    "#|#|#|#|#|# - b ",
    "#|# - # - #### #",
    "# ############ #",
    "#p             #",
    "################"
  ],

  local key = {
    "#": e.wall,
    "p": e.player,
    "e": e.exit,
    "b": e.box,
    "|": {
      factory: e.wire,
      params: {
        sides: ["up", "down"]
      }
    },
    "-": {
      factory: e.wire,
      params: {
        sides: ["left", "right"]
      }
    }
  },

  "entities": assemble([
    a.image([0, 0], image, key),
    e.lever({
      pos: [1, 2]
    }),
    a.piston({
      pos: [13, 4],
      dir: "right"
    }),

    [
      e.wire({
        pos: [x, 7],
        sides: ["down", "right"]
      }) for x in [1, 5, 9]
    ],
    [
      e.wire({
        pos: [x, 7],
        sides: ["down", "left"]
      }) for x in [3, 7, 11]
    ],
    [
      e.wire({
        pos: [x, 3],
        sides: ["up", "right"]
      }) for x in [3, 7]
    ],
    [
      e.wire({
        pos: [x, 3],
        sides: ["up", "left"]
      }) for x in [5, 9]
    ],
    e.wire({
      pos: [11, 4],
      sides: ["up", "right"]
    })
  ])
}
