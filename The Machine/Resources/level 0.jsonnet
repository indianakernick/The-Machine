local e = import "entities.libsonnet";
local common = import "common.libsonnet";

[
  e.makeBox({
    pos: [0, 0]
  }),
  e.makeButton({
    pos: [1, 0]
  }),
  e.makeExit({
    pos: [2, 0]
  })
]
