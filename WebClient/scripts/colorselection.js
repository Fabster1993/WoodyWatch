var redSlider = document.getElementById("redSlider");
var greenSlider = document.getElementById("greenSlider");
var blueSlider = document.getElementById("blueSlider");
var hourColorSelection = document.getElementById("hourColorSelection");
var minuteColorSelection = document.getElementById("minuteColorSelection");
var hourSelectionChecked = true;

redSlider.oninput = setColorPreview;
greenSlider.oninput = setColorPreview;
blueSlider.oninput = setColorPreview;


configureButton = document.getElementById("setColorButton");
configureButton.onclick = function ()
{
    let color = getDecimalColorCodeFromSliders();
    if(hourSelectionChecked)
    {
        console.log("Set hour color code: " + color);
        watch.setHourStrokeColor(color);
    }
    else
    {
        console.log("Set minutes color code: " + color);
        watch.setMinuteStrokeColor(color);
    }
}

function setColorPreview()
{
    var colorPreview = document.getElementById("colorPreview");
    colorPreview.style.fill = 'rgb(' + [redSlider.value, greenSlider.value, blueSlider.value].join(',') + ')';
}

hourColorSelection.onclick = function()
{
    hourColorSelection.className = "radio-button-checked";
    minuteColorSelection.className = "radio-button-unchecked";
    hourSelectionChecked = true;
    updateRgbSliders();
}

minuteColorSelection.onclick = function()
{
    hourColorSelection.className = "radio-button-unchecked";
    minuteColorSelection.className = "radio-button-checked";
    hourSelectionChecked = false;
    updateRgbSliders();
}

function getDecimalColorCodeFromSliders()
{
    color = parseInt(redSlider.value) * 65536;
    color = color + parseInt(greenSlider.value) * 256; 
    color = color + parseInt(blueSlider.value);
    return color;
}

function setDecimalColorCodeToSliders(colorCode)
{
    colorCode &= 16777215;
    redSlider.value = colorCode >>> 16;
    colorCode &= 65535;
    greenSlider.value = colorCode >>> 8;
    colorCode &= 255;
    blueSlider.value = colorCode;
    setColorPreview();
}

function updateRgbSliders()
{
    if(hourSelectionChecked)
    {
        watch.getHourStrokeColor(setDecimalColorCodeToSliders);
    }
    else
    {
        watch.getMinuteStrokeColor(setDecimalColorCodeToSliders); 
    }
}