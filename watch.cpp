#include "watch.h"
#include <QTime>
#include <QTimer>
#include "watchdial.h"
#include "ws2811impl.h"

#include <QDebug>

Watch::Watch()
    : QObject(nullptr),
      timer(nullptr),
      watchDial(nullptr),
      ledInterface(nullptr)
{
    timer = new QTimer;
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &Watch::showTime);

    ledInterface = new Ws2811Impl(WatchDial::getPixelQuantity());
    this->watchDial = new WatchDial(ledInterface);
}

qint32 Watch::calculateNextTimerTimeout()
{
    const QTime currentTime = QTime::currentTime();
    return (60 * 1000) - (currentTime.second() * 1000) - currentTime.msec();
}

Watch& Watch::getInstance()
{
    static Watch instance;
    return instance;
}

Watch::~Watch()
{
    delete timer;
    timer = nullptr;

    delete watchDial;
    watchDial = nullptr;
}

void Watch::initialize()
{
    showTime();
}

void Watch::setHourStrokeColor(quint32 hourStrokeColor)
{
    QColor color(hourStrokeColor);
    Configuration configuration = watchDial->getConfiguration();
    configuration.setHourStrokeColor(color);
    watchDial->setConfiguration(configuration);
    showTime();
}

void Watch::setMinuteStrokeColor(quint32 minuteStrokeColor)
{
    QColor color(minuteStrokeColor);
    Configuration configuration = watchDial->getConfiguration();
    configuration.setMinuteStrokeColor(color);
    watchDial->setConfiguration(configuration);
    showTime();
}

void Watch::showTime()
{
    watchDial->showTimeOfDay(QTime::currentTime());
    timer->start(calculateNextTimerTimeout());
}
