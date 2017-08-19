exports.rgbToHex = function(red, green, blue) {
  var redHex = intToHex2(red);
  var greenHex = intToHex2(green);
  var blueHex = intToHex2(blue);

  return redHex + greenHex + blueHex;
};

function intToHex2(int) {
  return ("0" + int.toString(16)).slice(-2);
}

exports.hexToRgb = function(hexColor) {
  var red = parseInt(hexColor.substring(0, 2), 16);
  var green = parseInt(hexColor.substring(2, 4), 16);
  var blue = parseInt(hexColor.substring(4, 6), 16);

  return [red, green, blue];
};
