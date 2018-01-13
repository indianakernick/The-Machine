{
  sheet: (import "sprites.atlas"),

  getSpriteID(name):: $.sheet.names[name],

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
    local found = std.foldl(find, array, {found: -1, index: 0}).found;
    if found == -1 then
      error "Item not found in array"
    else
      found
  ,

  layerNames: [
    "piston base",
    "lever",
    "dynamic",
    "static"
  ],

  getDepth(name)::
    $.indexOf($.layerNames, name) / std.length($.layerNames)
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
    "piston_head"
  ],
  collision_bitset_size: 32,

  getStaticCollisionComp(params):: {
    accepts: $.getNamedBitset($.collision_type_names, $.collision_bitset_size, params.accepts)
  },

  getDynamicCollisionComp(params):: {
    local allNames = $.collision_type_names,
    local size = $.collision_bitset_size,
    type: $.getNamedBit(allNames, size, params.type),
    pushed_by: $.getNamedBitset(allNames, size, params.pushed_by)
  },

  dir_names: [
    "up",
    "right",
    "down",
    "left"
  ],
  dir_bitset_size: 4,

  getDirBitsetComp(sides, rot):: {
    local count = if rot == "" then 0 else $.indexOf($.dir_names, rot),
    local bits = $.getNamedBitset($.dir_names, $.dir_bitset_size, sides),
    local shifted = bits << count,

    "sides": (shifted & 15) | ((shifted & 240) >> 4)
  },

  getDir(dir)::
    $.indexOf($.dir_names, dir)
  ,
}
