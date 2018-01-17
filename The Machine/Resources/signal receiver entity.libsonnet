local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "channel"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: "player"
    }),
    Position: params.pos,
    Power: {},
    Device: {},
    PowerOutput: common.getDirBitsetComp("all", ""),
    SignalReceiver: {
      channel: params.channel
    },
    SpritePosition: {
      depth: common.getDepth("over dynamic")
    },
    PowerSprite: {
      local id = common.getSpriteID("signal receiver " + params.channel + " 0"),

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
