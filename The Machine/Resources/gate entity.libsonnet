local common = import "common.libsonnet";

local gate_names = [
  "and",
  "or",
  "xor",
  "not",
  "nand",
  "nor",
  "xnor",
  "identity"
];

function(params) {
  components: common.checkParams(params, ["pos", "gate", "dir"]) {
    local unary = (params.gate == "not" || params.gate == "identity"),
    local inputSides = if unary then
      "down"
    else
      ["up", "down"]
    ,
    local outputSides = if unary then
      "up"
    else
      ["right", "left"]
    ,
    local rot = if "dir" in params then
      params.dir
    else
      ""
    ,
    local gateIndex = common.indexOf(gate_names, params.gate),

    StaticCollision: common.getStaticCollisionComp({
      accepts: "none"
    }),
    Position: params.pos,
    Power: {},
    PowerInput: common.getDirBitsetComp(inputSides, rot),
    PowerOutput: common.getDirBitsetComp(outputSides, rot),
    Gate: {
      fun: gateIndex
    },
    SpritePosition: {
      depth: common.getDepth("static"),
      [if rot != "" then "dir"]: common.getDir(rot)
    },
    StaticSprite: {
      sprite: common.getSpriteID("gate 0") + gateIndex,
      ticks: 0
    }
  }
}
