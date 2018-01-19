local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  "meta": {
    "size": [16, 9]
  },

  local image = [
    "****************",
    "*      b      e*",
    "*      b       *",
    "*      b       *",
    "*      b       *",
    "*      b       *",
    "*      b       *",
    "*p     b       *",
    "****************"
  ],

  local key = {
    "*": e.wall,
    "p": e.player,
    "e": e.exit,
    "b": e.box
  },

  "entities": assemble([
    a.image([0, 0], image, key)
  ])
}
