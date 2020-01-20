var redSlider = document.getElementById("redSlider");
var greenSlider = document.getElementById("greenSlider");
var blueSlider = document.getElementById("blueSlider");
var hourColorSelection = document.getElementById("hourColorSelection");
var minuteColorSelection = document.getElementById("minuteColorSelection");
var hourSelectionChecked = true;

connectARgbSliderWithTextEdit(redSlider);
connectARgbSliderWithTextEdit(greenSlider);
connectARgbSliderWithTextEdit(blueSlider);

configureButton = document.getElementById("configureButton");
configureButton.onclick = function ()
{
    color = parseInt(redSlider.value) * 65536;
    color = color + parseInt(greenSlider.value) * 256; 
    color = color + parseInt(blueSlider.value);

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

function connectARgbSliderWithTextEdit(slider) 
{
    slider.oninput = function()
    {
        setColorPreview();
    };
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
}

minuteColorSelection.onclick = function()
{

    hourColorSelection.className = "radio-button-unchecked";
    minuteColorSelection.className = "radio-button-checked";
    hourSelectionChecked = false;
}