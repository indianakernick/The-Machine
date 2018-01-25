local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "################",
    "###########   e#",
    "###########  ###",
    "##B ##   ##  ###",
    "##  ## b ##  ###",
    "#      p      ##",
    "#   #######   ##",
    "################",
    "################"
  ],

  entities: assemble([
    a.image([0, 0], image, null),
    e.radioactive_toggle({
      pos: [2, 4],
      dir: "down"
    }),
    e.radioactivity_detector({
      pos: [12, 4],
      dir: "down"
    }),
    e.gate({
      pos: [12, 5],
      dir: "up",
      gate: "not"
    }),
    a.piston({
      pos: [12, 6],
      dir: "up"
    })
  ])
}

