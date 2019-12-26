#include "watch.h"
#include <QTime>
#include <QTimer>
#include <watchdial.h>

#include <QDebug>

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

void Watch::initialize()
{
    showTime();
}

void Watch::setHourStrokeColor(quint32 hourStrokeColor)
{
    qDebug() << hourStrokeColor;
    Configuration configuration(QColor(hourStrokeColor), QColor(255, 0, 0));
    configureWatchDial(configuration);
    showTime();
}

void Watch::configureWatchDial(const Configuration& configuration)
{
    watchDial->configure(configuration);
}

void Watch::showTime()
{
    watchDial->showTimeOfDay(QTime::currentTime());
}
