local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "################",
    "##b#b##b##b#b###",
    "###b##b#b#b#b###",
    "###b###b###b####",
    "################",
    "#b###b#bbb#bb#b#",
    "#b#b#b##b##b#bb#",
    "##b#b##bbb#b##b#",
    "################"
  ],

  entities: assemble([
    a.image([0, 0], image, null)
  ])
}
