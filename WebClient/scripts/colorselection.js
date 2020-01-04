var rSlider = document.getElementById("rSlider");
var gSlider = document.getElementById("gSlider");
var bSlider = document.getElementById("bSlider");

connectARgbSliderWithTextEdit(rSlider, "rText");
connectARgbSliderWithTextEdit(gSlider, "gText");
connectARgbSliderWithTextEdit(bSlider, "bText");

configureButton = document.getElementById("configureButton");
configureButton.onclick = function (){
    color = parseInt(rSlider.value) * 65536;
    color = color + parseInt(gSlider.value) * 256; 
    color = color + parseInt(bSlider.value);
    var hourStrokeColor = document.getElementById("hourColor").checked;
    if(hourStrokeColor)
    {
        watch.setHourStrokeColor(color);
    }
    else
    {
        watch.setMinuteStrokeColor(color);
    }
}

function connectARgbSliderWithTextEdit(slider, textID) {
    slider.oninput = function(){
        var text = document.getElementById(textID);
        text.innerHTML = slider.value;
        setColorPreview();
    };
}

function setColorPreview() {
    var rSlider = document.getElementById("rSlider");
    var gSlider = document.getElementById("gSlider");
    var bSlider = document.getElementById("bSlider");
    var colorPreview = document.getElementById("colorPreview");
    colorPreview.setAttribute("fill", "#" + rgbToHex(rSlider.value) + rgbToHex(gSlider.value) + rgbToHex(bSlider.value));

}

var rgbToHex = function (rgb) { 
    var hex = Number(rgb).toString(16);
    if (hex.length < 2) {
         hex = "0" + hex;
    }
    return hex;
  };
