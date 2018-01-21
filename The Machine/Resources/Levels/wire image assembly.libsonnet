local e = import "entities.libsonnet";

local device = "d";
local cross = "c";
local vert = "|";
local hori = "-";
local smart = "+";

local getChar(image, x, y) =
  local height = std.length(image);

  if height == 0 then
    " "
  else if std.length(image[0]) == 0 then
    " "
  else if x < 0 || x >= std.length(image[0]) then
    " "
  else if y < 0 || y >= height then
    " "
  else
    image[height - y - 1][x]
;

local removeNull(array) =
  std.filter(function(x) x != null, array)
;

local smartWire(image, x, y) =
  local neighbors = [
    ["up",    getChar(image, x, y + 1)],
    ["right", getChar(image, x + 1, y)],
    ["down",  getChar(image, x, y - 1)],
    ["left",  getChar(image, x - 1, y)]
  ];
  local sides = [
    local name = pair[0];
    local char = pair[1];

    if char == " " then
      null
    else if char == device || char == smart || char == cross then
      name
    else if char == vert && (name == "up" || name == "down") then
      name
    else if char == hori && (name == "left" || name == "right") then
      name

    for pair in neighbors
  ];
  e.wire({
    pos: [x, y],
    "sides": removeNull(sides)
  })
;

function(pos, image) [
  [
    local char = getChar(image, x, y);

    if char == cross then
      e.cross_wire({
        pos: [x, y]
      })
    else if char == vert then
      e.wire({
        pos: [x, y],
        sides: ["up", "down"]
      })
    else if char == hori then
      e.wire({
        pos: [x, y],
        sides: ["left", "right"]
      })
    else if char == smart then
      smartWire(image, x, y)
    else
      null
    for x in std.makeArray(std.length(image[0]), function(x) x + pos[0])
  ] for y in std.makeArray(std.length(image), function(y) y + pos[1])
]
