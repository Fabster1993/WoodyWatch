#include "Animations/blinkanimation.h"
#include "watchdial.h"
#include <QColor>
#include <QTimer>
#include <QDebug>

const quint16 numberOfBlinks = 5;
const quint16 blinkPeriod = 300;
const auto color = QColor(0, 56, 66);

BlinkAnimation::BlinkAnimation(WatchDial& watchDial, QObject *parent)
    : Animation(watchDial, parent),
      counter(0)
{

}

void BlinkAnimation::play()
{
    if(counter == 0)
    {
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
        counter = 0;
        timer->stop();
    }
}

QString BlinkAnimation::getName()
{
    return QString("Blink");
}

void BlinkAnimation::lightsOff()
{
    watchDial.resetPixels();
    watchDial.render();
}

void BlinkAnimation::lightsOn()
{
    for(quint16 hour = 0; hour < 12; ++hour)
    {
        watchDial.setHourPixel(hour, color);
    }
    watchDial.render();
}
