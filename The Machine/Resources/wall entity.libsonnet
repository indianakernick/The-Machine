local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: "none"
    }),
    Position: params.pos,
    SpritePosition: {
      depth: common.getDepth("static")
    },
    StaticSprite: {
      sprite: common.getSpriteID("wall"),
      animated: false
    }
  }
}
