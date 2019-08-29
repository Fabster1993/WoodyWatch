#include "watch.h"
#include <QTime>
#include <QTimer>
#include <watchdial.h>

Watch::Watch(quint16 updateCycleTime, WatchDial* watchDial)
    : QObject(nullptr),
      timer(nullptr),
      watchDial(watchDial)
{
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(updateCycleTime);
}

Watch::~Watch()
{
    if(timer != nullptr)
    {
        delete timer;
        timer = nullptr;
    }
    if(watchDial != nullptr)
    {
        delete watchDial;
        watchDial = nullptr;
    }
}

void Watch::showTime()
{
    watchDial->showTimeOfDay(QTime::currentTime());
}
