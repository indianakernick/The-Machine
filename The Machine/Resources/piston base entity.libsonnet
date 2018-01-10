local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "dir"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: "piston_head"
    }),
    Position: params.pos,
    Power: {},
    Device: {},
    PowerInput: common.getDirBitsetComp(["right", "down", "left"], params.dir),
    SpritePosition: {
      depth: common.getDepth("piston base"),
      dir: common.getDir(params.dir)
    },
    StaticSprite: {
      sprite: common.getSpriteID("piston base"),
      animated: false
    }
  }
}
