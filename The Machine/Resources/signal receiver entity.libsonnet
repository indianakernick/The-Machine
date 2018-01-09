local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "channel"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: "none"
    }),
    Position: params.pos,
    Power: {},
    PowerOutput: common.getDirBitsetComp("all", ""),
    SignalReceiver: {
      channel: params.channel
    },
    SpritePosition: {
      depth: common.getDepth("static")
    },
    PowerSprite: {
      local spriteName = "signal receiver channel " + params.channel,
      transition: common.getSpriteID(spriteName + " power 0"),
      on: common.getSpriteID(spriteName + " on 0")
    }
  }
}
