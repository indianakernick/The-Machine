local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "radioactive"]) {
    DynamicCollision: common.getDynamicCollisionComp({
      type: "box",
      pushed_by: ["player", "piston_head"]
    }),
    Movement: {},
    Position: params.pos,
    Radioactivity: {
      enabled: if "radioactive" in params then params.radioactive else false
    },
    SpritePosition: {
      depth: common.getDepth("dynamic")
    },
    RadioactivitySprite: {
      sprite: common.getSpriteID("box 0")
    }
  }
}
