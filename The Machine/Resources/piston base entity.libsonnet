local common = import "common.libsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "dir"]) {
    local rot = if "dir" in params then
      params.dir
    else
      ""
    ,
    
    StaticCollision: common.getStaticCollisionComp({
      accepts: "piston_head"
    }),
    Position: params.pos,
    Power: {},
    PowerInput: common.getDirBitsetComp(["right", "down", "left"], rot),
    SpritePosition: {
      depth: common.getDepth("piston base"),
      [if rot != "" then "dir"]: common.getDir(rot)
    },
    StaticSprite: {
      sprite: common.getSpriteID("piston base"),
      animated: false
    }
  }
}
