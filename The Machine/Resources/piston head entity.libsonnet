local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "dir"]) {
    DynamicCollision: common.getDynamicCollisionComp({
      type: "piston_head",
      pushed_by: "none"
    }),
    Position: params.pos,
    Movement: {},
    Device: {},
    Piston: {
      base_pos: params.pos,
      dir: common.getDir(params.dir)
    },
    SpritePosition: {
      depth: common.getDepth("dynamic"),
      dir: common.getDir(params.dir)
    },
    StaticSprite: {
      sprite: common.getSpriteID("piston head"),
      ticks: 0
    }
  }
}
