local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "################",
    "#      b      e#",
    "#      b       #",
    "#      b       #",
    "#      b       #",
    "#      b       #",
    "#      b       #",
    "#p     b       #",
    "################"
  ],

  entities: assemble([
    a.image([0, 0], image, null)
  ])
}
