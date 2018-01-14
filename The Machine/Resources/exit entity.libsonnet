local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: "player"
    }),
    Position: params.pos,
    Exit: {},
    SpritePosition: {
      depth: common.getDepth("static")
    },
    StaticSprite: {
      sprite: common.getSpriteID("exit 0"),
      ticks: 4
    }
  }
}
