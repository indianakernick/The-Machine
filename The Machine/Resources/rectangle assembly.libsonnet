function(pos, size, factory) [
  [
    factory([x, y])
    for x in std.makeArray(size[0], function(x) x + pos[0])
  ] for y in std.makeArray(size[1], function(y) y + pos[1])
]
