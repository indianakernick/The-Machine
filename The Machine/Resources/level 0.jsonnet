local e = import "entities.libsonnet";
local common = import "common.libsonnet";

[
  {
    components: {
      StaticCollision: common.getStaticCollisionComp({
        type: "air",
        accepts: "all"
      }),
      PowerInput: common.getDirBitsetComp(["right", "left"])
    }
  }
]
