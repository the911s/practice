exports.rgbToHex = function(red, green, blue) {
  var redHex = pad(red.toString(16));
  var greenHex = pad(green.toString(16));
  var blueHex = pad(blue.toString(16));

  return redHex + greenHex + blueHex;
};

function pad(hexValue) {
  return ("0" + hexValue).slice(-2);
}

exports.hexToRgb = function(hexColor) {
  var red = parseInt(hexColor.substring(0, 2), 16);
  var green = parseInt(hexColor.substring(2, 4), 16);
  var blue = parseInt(hexColor.substring(4, 6), 16);

  return [red, green, blue];
};
