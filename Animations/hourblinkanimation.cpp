#include "Animations/hourblinkanimation.h"
#include "watchdial.h"
#include "watch.h"
#include <QColor>
#include <QTimer>

const quint16 numberOfBlinks = 5;
const quint16 blinkPeriod = 200;

HourBlinkAnimation::HourBlinkAnimation(WatchDial& watchDial, QObject *parent)
    : Animation(watchDial, parent)
{

}

void HourBlinkAnimation::play()
{
    if(counter == 0)
    {
        lightsOff();
        timer->start(blinkPeriod);
    }
    if(counter % 2)
    {
        lightsOff();
    }
    else
    {
        lightsOn();
    }
    ++counter;
    if(counter == numberOfBlinks * 2)
    {
        finishAnimation();
    }
}

QString HourBlinkAnimation::getName()
{
    return QString("Hour blink");
}

void HourBlinkAnimation::lightsOn()
{
    for(quint16 hour = 0; hour < 12; ++hour)
    {
        watchDial.setHourPixel(hour, Watch::getInstance().getHourStrokeColor());
    }
    watchDial.render();
}
