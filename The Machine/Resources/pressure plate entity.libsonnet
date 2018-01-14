local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "heavy"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: "all"
    }),
    Position: params.pos,
    PressurePlate: {
      heavy: params.heavy
    },
    Power: {},
    Device: {},
    PowerOutput: common.getDirBitsetComp("all", ""),
    SpritePosition: {
      depth: common.getDepth("static")
    },
    local weightName = if params.heavy then "heavy" else "light",
    PowerSprite: common.getTransitionPowerSpriteComp("pressure plate " + weightName + " 0")
  }
}
