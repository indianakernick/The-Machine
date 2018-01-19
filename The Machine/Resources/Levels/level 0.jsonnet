local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  "meta": {
    "size": [16, 9]
  },

  local image = [
    "****************",
    "*             e*",
    "*              *",
    "*              *",
    "*              *",
    "*              *",
    "*              *",
    "*p             *",
    "****************",
  ],

  local key = {
    "*": e.wall,
    "p": e.player,
    "e": e.exit
  },

  "entities": assemble([
    a.image([0, 0], image, key)
  ])
}
