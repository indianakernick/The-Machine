local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "heavy"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: ["player", "box"]
    }),
    Position: params.pos,
    PressurePlate: {
      heavy: params.heavy
    },
    Power: {},
    PowerOutput: common.getDirBitsetComp("all", ""),
    SpritePosition: {
      depth: common.getDepth("static")
    },
    PowerSprite: {
      local weightName = if params.heavy then "heavy" else "light",
      transition: common.getSpriteID("pressure plate " + weightName + " 0")
    }
  }
}
