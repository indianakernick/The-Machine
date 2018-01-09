local e = import "entities.libsonnet";
local common = import "common.libsonnet";

[
  e.box({
    pos: [0, 0]
  }),
  e.air({
    pos: [0, 0]
  }),
  e.button({
    pos: [1, 1]
  }),
  e.gate({
    pos: [1, 0],
    gate: "xor"
  }),
  e.exit({
    pos: [2, 0]
  }),
  e.lever({
    pos: [3, 0]
  })
]
