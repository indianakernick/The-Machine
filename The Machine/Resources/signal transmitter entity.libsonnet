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
      local spriteName = "signal transmitter channel " + params.channel,
      local onID = common.getSpriteID(spriteName + " on 0"),

      low: {
        start: onID,
        dir: 0
      },
      rise: {
        start: onID,
        dir: 1
      },
      fall: {
        start: onID,
        dir: 0
      },
      high: {
        start: onID,
        dir: 1
      }
    }
  }
}
