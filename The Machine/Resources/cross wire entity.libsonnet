local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: "player"
    }),
    Position: params.pos,
    CrossWire: {},
    SpritePosition: {
      depth: common.getDepth("static")
    },
    CrossWireSprite: {
      sprite: common.getSpriteID("cross wire 0 0")
    }
  }
}
