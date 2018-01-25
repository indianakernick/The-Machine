local e = import "entities.libsonnet";
local a = import "assemblies.libsonnet";
local assemble = import "assemble.libsonnet";

{
  meta: {
    size: [16, 9]
  },

  local image = [
    "######### B#####",
    "#  d # B#b d+#e ",
    "#  +-   #b #d   ",
    "#  d #  #b d+## ",
    "#  ### ##b #d   ",
    "##         d+## ",
    "## d d d+  #d   ",
    "#p +d+#d+# d+   ",
    "###  #####    ##"
  ],

  entities: assemble([
    a.image([0, 0], image, null),
    a.wire_image([0, 0], image),
    a.piston({
      pos: [9, 8],
      dir: "down"
    }),
    e.pressure_plate({
      pos: [3, 7],
      heavy: true
    }),
    a.piston({
      pos: [6, 7],
      dir: "down"
    }),
    e.radioactivity_detector({
      pos: [11, 7],
      dir: "left"
    }),
    e.radioactive_toggle({
      pos: [5, 6],
      dir: "right"
    }),
    e.gate({
      pos: [12, 6],
      dir: "right",
      gate: "xor"
    }),
    e.gate({
      pos: [13, 6],
      dir: "right",
      gate: "not"
    }),
    a.piston({
      pos: [14, 6],
      dir: "right"
    }),
    e.pressure_plate({
      pos: [3, 5],
      heavy: true
    }),
    e.radioactivity_detector({
      pos: [11, 5],
      dir: "left"
    }),
    e.gate({
      pos: [12, 4],
      dir: "right",
      gate: "xor"
    }),
    e.gate({
      pos: [13, 4],
      dir: "right",
      gate: "not"
    }),
    a.piston({
      pos: [14, 4],
      dir: "right"
    }),
    e.radioactivity_detector({
      pos: [11, 3],
      dir: "left"
    }),
    e.lever({
      pos: [3, 2]
    }),
    e.lever({
      pos: [5, 2]
    }),
    e.pressure_plate({
      pos: [7, 2],
      heavy: true
    }),
    e.gate({
      pos: [12, 2],
      dir: "right",
      gate: "xor"
    }),
    e.gate({
      pos: [13, 2],
      dir: "right",
      gate: "not"
    }),
    a.piston({
      pos: [14, 2],
      dir: "right"
    }),
    e.gate({
      pos: [4, 1],
      dir: "up",
      gate: "xor"
    }),
    a.piston({
      pos: [7, 1],
      dir: "up"
    }),
    e.radioactivity_detector({
      pos: [11, 1],
      dir: "left"
    }),
    a.piston({
      pos: [4, 0],
      dir: "left"
    })
  ])
}
