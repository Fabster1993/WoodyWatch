#include "increasingcircleanimation.h"
#include "watchdial.h"
#include "watch.h"
#include <QColor>
#include <QTimer>

const quint16 blinkPeriod = 500;

IncreasingCircleAnimation::IncreasingCircleAnimation(WatchDial& watchDial, QObject* parent)
    : Animation(watchDial, parent)
{

}

void IncreasingCircleAnimation::play()
{
    if(counter == 0)
    {
        lightsOff();
        timer->start(blinkPeriod);
        lightsOn();
    }
    else
    {
        lightsOn();
    }
    if(counter == WatchDial::getPixelPerHourStroke())
    {
        finishAnimation();
        return;
    }
    ++counter;
}

QString IncreasingCircleAnimation::getName()
{
    return QString("Increasing cirlce");
}

void IncreasingCircleAnimation::lightsOn()
{
    for(quint16 hour = 0; hour < 12; ++hour)
    {
        quint16 startPixel = watchDial.getHourStartPixel(hour);
        watchDial.setPixelRange(startPixel, startPixel + counter, Watch::getInstance().getHourStrokeColor());
    }
    watchDial.render();
}
