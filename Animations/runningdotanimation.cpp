#include "runningdotanimation.h"
#include "watchdial.h"
#include "watch.h"
#include <QColor>
#include <QTimer>

const quint16 blinkPeriod = 40;

RunningDotAnimation::RunningDotAnimation(WatchDial& watchDial, QObject* parent)
    : Animation(watchDial, parent)
{

}

void RunningDotAnimation::play()
{
    lightsOff();
    if(counter == 0)
    {
        timer->start(blinkPeriod);
        lightsOn();
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

QString RunningDotAnimation::getName()
{
    return QString("Running dot");
}

void RunningDotAnimation::lightsOn()
{
    watchDial.setMinutePixel(counter, Watch::getInstance().getMinuteStrokeColor());
    watchDial.render();
}
