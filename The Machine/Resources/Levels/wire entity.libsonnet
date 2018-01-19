local common = import "common.libsonnet";

local wireSprites = [
  {dir: "up", sprite: "0"},    // none
  {dir: "up", sprite: "1"},    // up
  {dir: "right", sprite: "1"}, // right
  {dir: "up", sprite: "2"},    // up right
  {dir: "down", sprite: "1"},  // down
  {dir: "up", sprite: "3"},    // up down
  {dir: "right", sprite: "2"}, // right down
  {dir: "up", sprite: "4"},    // up right down
  {dir: "left", sprite: "1"},  // left
  {dir: "left", sprite: "2"},  // up left
  {dir: "right", sprite: "3"}, // right left
  {dir: "left", sprite: "4"},  // up right left
  {dir: "down", sprite: "2"},  // down left
  {dir: "down", sprite: "4"},  // up down left
  {dir: "right", sprite: "4"}, // right down left
  {dir: "up", sprite: "5"}
];

local getWireDir(sides) =
  local sidesSet = common.getDirBitsetComp(sides, "").sides;
  common.getDir(wireSprites[sidesSet].dir)
;

local getWireSprite(sides) =
  local sidesSet = common.getDirBitsetComp(sides, "").sides;
  "wire " + wireSprites[sidesSet].sprite + " 0"
;

function(params) {
  components: common.checkParams(params, ["pos", "sides"]) {
    StaticCollision: common.getStaticCollisionComp({
      accepts: "none"
    }),
    Position: params.pos,
    Power: {},
    Wire: common.getDirBitsetComp(params.sides, ""),
    SpritePosition: {
      depth: common.getDepth("static"),
      dir: getWireDir(params.sides)
    },
    PowerSprite: common.getTransitionPowerSpriteComp(getWireSprite(params.sides))
  }
}
