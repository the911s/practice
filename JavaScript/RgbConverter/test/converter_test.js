var expect = require("chai").expect;
var converter = require("../app/converter");

describe("Color code converter", function() {
  describe("RGB to Hex conversion", function() {
    it("converts some basic colors", function() {
      var redHex = converter.rgbToHex(255, 0, 0);
      // var greenHex = converter.rgbToHex(0, 255, 0);
      // var blueHex = converter.rgbToHex(0, 0, 255);

      expect(redHex).to.equal("ff0000");
      // expect(redHex).to.equal("00ff00");
      // expect(redHex).to.equal("0000ff");
    });
  });

  describe("Hex to RGB conversion", function() {
    it("converts some basic colors", function() {
      var red = converter.hexToRgb("ff0000");
      var green = converter.hexToRgb("00ff00");
      var blue = converter.hexToRgb("0000ff");

      expect(red).to.deep.equal([255, 0, 0]);
      expect(green).to.deep.equal([0, 255, 0]);
      expect(blue).to.deep.equal([0, 0, 255]);
    });
  });
});