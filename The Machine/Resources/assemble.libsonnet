local assemble = function(assembly)
  local fun(array, current) =
    if std.type(current) == "array" then
      array + assemble(current)
    else
      array + [current]
  ;
  std.foldl(fun, assembly, [])
;

assemble
