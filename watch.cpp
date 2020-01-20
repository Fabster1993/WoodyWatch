#include "watch.h"
#include <QTime>
#include <QTimer>
#include "watchdial.h"
#include "ws2811impl.h"
#include <QCoreApplication>
#include "Animations/animationfactory.h"
#include "Animations/animation.h"

Watch::Watch()
    : QObject(nullptr),
      timer(nullptr),
      watchDial(nullptr),
      ledInterface(nullptr)
{
    timer = new QTimer;
    timer->setSingleShot(true);
    timer->setTimerType(Qt::PreciseTimer);
    connect(timer, &QTimer::timeout, this, &Watch::showTime);

    ledInterface = new Ws2811Impl(WatchDial::getPixelQuantity());
    this->watchDial = new WatchDial(ledInterface);
}

qint32 Watch::calculateTimeUntilNextMinuteChange()
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
    configuration = Configuration::load(QCoreApplication::applicationDirPath());
    showTime();
}

void Watch::setHourStrokeColor(quint32 hourStrokeColor)
{
    QColor color(hourStrokeColor);
    configuration.setHourStrokeColor(color);
    showTime();
    configuration.persist(QCoreApplication::applicationDirPath());
}

void Watch::setMinuteStrokeColor(quint32 minuteStrokeColor)
{
    QColor color(minuteStrokeColor);
    configuration.setMinuteStrokeColor(color);
    showTime();
    configuration.persist(QCoreApplication::applicationDirPath());
}

void Watch::showAnimation()
{
    AnimationFactory::create("unused", *watchDial).play();
}

void Watch::showTime()
{
    QTime currentTime = QTime::currentTime();
    if(currentTime.minute() == 0)
    {
        // showAnimation();
    }
    watchDial->showTimeOfDay(currentTime, configuration.getHourStrokeColor(), configuration.getMinuteStrokeColor());
    timer->start(calculateTimeUntilNextMinuteChange());
}
