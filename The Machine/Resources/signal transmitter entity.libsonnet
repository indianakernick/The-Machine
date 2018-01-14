local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "channel"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: "none"
    }),
    Position: params.pos,
    Power: {},
    Device: {},
    PowerInput: common.getDirBitsetComp("all", ""),
    SignalTransmitter: {
      channel: params.channel
    },
    SpritePosition: {
      depth: common.getDepth("static")
    },
    PowerSprite: {
      local id = common.getSpriteID("signal transmitter " + params.channel + " 0"),

      low: {
        start: id,
        dir: 0
      },
      rise: {
        start: id,
        dir: 1
      },
      fall: {
        start: id,
        dir: 0
      },
      high: {
        start: id,
        dir: 1
      }
    }
  }
}
