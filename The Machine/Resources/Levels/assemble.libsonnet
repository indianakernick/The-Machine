local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";

local assemble = function(assembly)
  local fun(array, current) =
    if std.type(current) == "array" then
      array + assemble(current)
    else if std.type(current) == "object" then
      array + [current]
    else
      error "Encountered invalid object while assembling " + current
  ;
  std.foldl(fun, assembly, [])
;

assemble
