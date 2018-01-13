local common = import "common.libsonnet";
local maxDelay = 8;

function(params) {
  components: common.checkParams(params, ["pos", "length", "dir"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: "none"
    }),
    Position: params.pos,
    Power: {},
    PowerInput: common.getDirBitsetComp("down", params.dir),
    PowerOutput: common.getDirBitsetComp("up", params.dir),
    Delay: {
      length: params.length
    },
    SpritePosition: {
      depth: common.getDepth("static"),
      dir: common.getDir(params.dir)
    },
    StaticSprite: {
      sprite: common.getSpriteID("delay 0") + params.length - 1,
      animated: false
    }
  }
}
