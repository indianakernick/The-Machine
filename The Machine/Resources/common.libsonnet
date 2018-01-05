{
  checkParams(params, validNames)::
    local paramNames = std.set(std.objectFields(params));
    local invalidNames = std.setDiff(paramNames, std.set(validNames));
  {
    [if (std.length(invalidNames) > 0) then
      error "Invalid parameters: " + invalidNames
    ]:: null
  },

  indexOf(array, item)::
    local find(info, current) =
      if info.found == -1 && item == current then
        {found: info.index, index: info.index + 1}
      else
        {found: info.found, index: info.index + 1}
    ;
    std.foldl(find, array, {found: -1, index: 0}).found
  ,

  getNamedBit(allNames, size, name)::
    if name == "all" then
      (1 << size) - 1
    else if name == "none" then
      0
    else
      1 << $.indexOf(allNames, name)
  ,

  getNamedBitset(allNames, size, names)::
    if std.type(names) == "string" then
      $.getNamedBit(allNames, size, names)
    else
      std.foldl(
        function(set, name) set | $.getNamedBit(allNames, size, name),
        names,
        0
      )
  ,

  collision_type_names: [
    "box",
    "player",
    "wall",
    "air"
  ],
  collision_bitset_size: 32,

  getCollisionComp(params):: {
    local allNames = $.collision_type_names,
    local size = $.collision_bitset_size,

    type: $.getNamedBit(allNames, size, params.type),
    pushed_by: $.getNamedBitset(allNames, size, params.pushed_by),
    accepts: $.getNamedBitset(allNames, size, params.accepts)
  },

  dir_names: [
    "up",
    "right",
    "down",
    "left"
  ],
  dir_bitset_size: 4,

  getDirBitsetComp(params):: {
    sides: $.getNamedBitset($.dir_names, $.dir_bitset_size, params.sides)
  }
}
