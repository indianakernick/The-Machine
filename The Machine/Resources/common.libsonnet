{
  checkParams(params, validNames)::
    local paramNames = std.set(std.objectFields(params));
    local invalidNames = std.setDiff(paramNames, std.set(validNames));
  {
    [if (std.length(invalidNames) > 0) then
      error "Invalid parameters: " + invalidNames
    ]:: null
  },

  collision_type_names: [
    "box",
    "player",
    "wall",
    "air"
  ],

  indexOf(array, item)::
    local find(info, current) =
      if info.found == -1 && item == current then
        {found: info.index, index: info.index + 1}
      else
        {found: info.found, index: info.index + 1}
    ;
    std.foldl(find, array, {found: -1, index: 0}).found
  ,

  getCollisionBit(name)::
    if name == "all" then
      (1 << 32) - 1
    else if name == "none" then
      0
    else
      1 << $.indexOf($.collision_type_names, name)
  ,

  getCollisionBitset(names)::
    if std.type(names) == "string" then
      $.getCollisionBit(names)
    else
      std.foldl(
        function(set, name) set | $.getCollisionBit(name),
        names,
        0
      )
  ,

  getCollisionComp(params):: {
    type: $.getCollisionBit(params.type),
    pushed_by: $.getCollisionBitset(params.pushed_by),
    accepts: $.getCollisionBitset(params.accepts)
  }
}
