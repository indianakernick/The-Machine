local e = import "entities.libsonnet";
local common = import "common.libsonnet";

[
  {
    components: {
      Collision: common.getCollisionComp({
        type: "air",
        pushed_by: "none",
        accepts: "all"
      })
    }
  }
]
