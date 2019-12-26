connectARgbSliderWithTextEdit("rSlider", "rText");
connectARgbSliderWithTextEdit("gSlider", "gText");
connectARgbSliderWithTextEdit("bSlider", "bText");
var watch;

configureButton = document.getElementById("configureButton");
configureButton.onclick = function (){
    var rSlider = document.getElementById("rSlider");
    var gSlider = document.getElementById("gSlider");
    var bSlider = document.getElementById("bSlider");
    color = rSlider.value >> 16;
    color += gSlider.value >> 8; 
    color += bSlider.value;
    watch.setHourStrokeColor(color)
}

//BEGIN SETUP
window.onload = function () {
    var baseUrl = "ws://192.168.1.117:443/";
    var socket = new WebSocket(baseUrl);

    socket.onclose = function () {
        console.error("web channel closed");
    };
    socket.onerror = function (error) {
        console.error("web channel error: " + error);
    };
    socket.onopen = function () {
        new QWebChannel(socket, function (channel) {
            // make core object accessible globally
            window.watch = channel.objects.watch;
            channel.objects.watch.setHourStrokeColor(0);
        });
    }
}
            //END SETUP

function connectARgbSliderWithTextEdit(sliderID, textID) {
    var slider = document.getElementById(sliderID);
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
