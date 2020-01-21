var showAnimation = document.getElementById("showAnimation");
var animationsMenuButton = document.getElementById("animationsMenuButton");
var animations = document.getElementById("animations");
var setAnimation = document.getElementById("setAnimation");

showAnimation.onclick = function()
{
    window.watch.showAnimation(animationsMenuButton.innerHTML);
}

animationsMenuButton.onclick = function() 
{
    animations.classList.toggle("show");
}

setAnimation.onclick = function()
{
    window.watch.setAnimation(animationsMenuButton.innerHTML);
}

function assembleAnimationsMenu(animationList)
{
    var lines = animationList.split('\n');
    for(var i = 0;i < lines.length - 1;i++)
    {
        addAnimation(lines[i]);
    }
    window.watch.getAnimationName(animationSelected);
}

function animationSelected(animation)
{
    animationsMenuButton.innerHTML = animation;
}

function addAnimation(animation)
{
    var action = document.createElement("a");
    action.innerHTML = animation;
    action.onclick = function() { animationSelected(animation); };
    animations.appendChild(action);
}

// Close the dropdown menu if the user clicks outside of it
window.onclick = function(event) 
{
    if (!event.target.matches(".drop-down-button")) 
    {
      var dropdowns = document.getElementsByClassName("dropdown-content");
      var i;
      for (i = 0; i < dropdowns.length; i++) 
      {
        var openDropdown = dropdowns[i];
        if (openDropdown.classList.contains('show')) 
        {
          openDropdown.classList.remove('show');
        }
      }
    }
}