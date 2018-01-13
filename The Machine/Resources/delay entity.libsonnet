local common = import "common.libsonnet";

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
      sprite: common.getSpriteID("gate 7"),
      animated: false
    }
  }
}
