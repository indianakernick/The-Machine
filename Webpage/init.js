Module["print"] = function() {
  console.log(Array.prototype.slice.call(arguments).join(" "));
};
Module["printErr"] = function() {
  console.warn(Array.prototype.slice.call(arguments).join(" "));
};
Module["canvas"] = document.querySelector("canvas");

function resume() {
  var sdl = Module["SDL2"];
  if (!sdl) return;
  var ctx = sdl.audioContext;
  if (!ctx) return;
  if (ctx.state == "suspended") {
    ctx.resume();
  }
}

window.addEventListener("mousemove", resume);
window.addEventListener("mousedown", resume);
window.addEventListener("keydown", resume);
document.addEventListener("readystatechange", resume);
