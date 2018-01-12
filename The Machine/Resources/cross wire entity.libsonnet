local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: "player"
    }),
    Position: params.pos,
    CrossWire: {},
    PowerOutput: common.getDirBitsetComp("all", ""),
    SpritePosition: {
      depth: common.getDepth("static")
    },
    CrossWireSprite: {
      both: common.getSpriteID("cross wire 0 0"),
      inverted: common.getSpriteID("cross wire 1 0"),
      hori_off: common.getSpriteID("cross wire 2 0"),
      hori_on: common.getSpriteID("cross wire 3 0")
    }
  }
}
