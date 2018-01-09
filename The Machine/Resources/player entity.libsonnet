local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos"]) {
    DynamicCollision: common.getDynamicCollisionComp({
      type: "player",
      pushed_by: ["box", "piston_head"]
    }),
    Position: params.pos,
    Movement: {},
    Weight: {
      heavy: false
    },
    PlayerAction: {},
    SpritePosition: {
      depth: common.getDepth("dynamic")
    },
    StaticSprite: {
      sprite: common.getSpriteID("player"),
      animated: false
    }
  }
}
