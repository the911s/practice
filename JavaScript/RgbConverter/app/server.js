var express = require("express");
var app = express();
var converter = require("./converter");

const port = 3000;

app.get("/rgbToHex",function(req, res) {
  var red = parseInt(req.query.red);
  var green = parseInt(req.query.green);
  var blue = parseInt(req.query.blue);

  var hex = converter.rgbToHex(red, green, blue);

  res.send(hex);
})

app.get("/hexToRgb", function(req, res) {
  var hex = req.query.hex;
  var rgb = converter.hexToRgb(hex);

  res.send(rgb)
})

app.listen(port, function() {
  console.log("RgbToHex server running on port " + port);
})
