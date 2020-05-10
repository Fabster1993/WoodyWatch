#include "pingponganimation.h"
#include "watchdial.h"
#include "watch.h"
#include <QColor>
#include <QTimer>

const quint16 blinkPeriod = 400;

PingPongAnimation::PingPongAnimation(WatchDial& watchDial, QObject* parent)
    : Animation(watchDial, parent)
{

}

void PingPongAnimation::play()
{
    lightsOff();
    if(counter == 0)
    {
        timer->start(blinkPeriod);
        watchDial.setMinutePixel(1, Watch::getInstance().getMinuteStrokeColor());
        watchDial.render();
    }
    else
    {
        lightsOn();
    }
    if(counter == 60)
    {
        finishAnimation();
        return;
    }
    ++counter;
}

QString PingPongAnimation::getName()
{
    return QString("Ping pong");
}

void PingPongAnimation::lightsOn()
{
    if(counter % 2)
    {
        watchDial.setMinutePixel(30 + counter / 2, Watch::getInstance().getMinuteStrokeColor());
    }
    else
    {
        quint16 counterDividedByTwo = counter / 2;
        watchDial.setMinutePixel(counter - counterDividedByTwo, Watch::getInstance().getMinuteStrokeColor());
    }
    watchDial.render();
}
