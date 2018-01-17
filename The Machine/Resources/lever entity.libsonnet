local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: "player"
    }),
    Position: params.pos,
    Power: {},
    Lever: {},
    Device: {},
    PowerOutput: common.getDirBitsetComp("all", ""),
    SpritePosition: {
      depth: common.getDepth("over dynamic")
    },
    PowerSprite: common.getTransitionPowerSpriteComp("lever 0")
  }
}
