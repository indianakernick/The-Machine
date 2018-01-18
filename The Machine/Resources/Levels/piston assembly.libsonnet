local e = import "entities.libsonnet";

function(params) [
  e.piston_head(params),
  e.piston_base(params)
]
