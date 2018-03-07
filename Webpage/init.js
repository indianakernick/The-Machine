Module["print"] = function() {
  console.log(Array.prototype.slice.call(arguments).join(" "));
};
Module["printErr"] = function() {
  console.warn(Array.prototype.slice.call(arguments).join(" "));
};
Module["canvas"] = document.querySelector("canvas");