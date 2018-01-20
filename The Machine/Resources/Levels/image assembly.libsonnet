local e = import "entities.libsonnet";

local defaultKey = {
  "#": e.wall,
  "p": e.player,
  "e": e.exit,
  "b": e.box
};

local readKey(keyObj, position) =
  if std.type(keyObj) == "function" then
    keyObj({
      pos: position
    })
  else if std.type(keyObj) == "object" then
    if "params" in keyObj then
      keyObj.factory({
        pos: position
      } + keyObj.params)
    else
      keyObj.factory({
        pos: position
      })
  else
    error "Invalid key object type"
;

function(pos, image, key) [
  [
    local char = image[std.length(image) - y - 1][x];

    if key == null && char in defaultKey then
      readKey(defaultKey[char], [x, y])
    else if key != null && char in key then
      readKey(key[char], [x, y])
    else
      null
    for x in std.makeArray(std.length(image[0]), function(x) x + pos[0])
  ] for y in std.makeArray(std.length(image), function(y) y + pos[1])
]
