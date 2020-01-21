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
    connect(timer, &QTimer::timeout, this, &Watch::onMinutePassed);

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
    startAnimation();
}

void Watch::setHourStrokeColor(quint32 hourStrokeColor)
{
    QColor color(hourStrokeColor);
    configuration.setHourStrokeColor(color);
    showTimeOfDay();
    configuration.persist(QCoreApplication::applicationDirPath());
}

void Watch::setMinuteStrokeColor(quint32 minuteStrokeColor)
{
    QColor color(minuteStrokeColor);
    configuration.setMinuteStrokeColor(color);
    showTimeOfDay();
    configuration.persist(QCoreApplication::applicationDirPath());
}

void Watch::setAnimation(const QString animationName)
{
    configuration.setAnimation(animationName);
    configuration.persist(QCoreApplication::applicationDirPath());
}

QColor Watch::getHourStrokeColor() const
{
    return configuration.getHourStrokeColor();
}

QColor Watch::getMinuteStrokeColor() const
{
    return configuration.getMinuteStrokeColor();
}

QString Watch::getAnimationName()
{
    return configuration.getAnimation();
}

void Watch::startAnimation()
{
    AnimationFactory::create(configuration.getAnimation(), *watchDial).play();

}

void Watch::showAnimation(const QString animation)
{
    AnimationFactory::create(animation, *watchDial).play();
}

void Watch::onMinutePassed()
{
    if(QTime::currentTime().minute() == 0)
    {
        startAnimation();
    }
    else
    {
        showTimeOfDay();
    }
}

void Watch::showTimeOfDay()
{
    watchDial->showTime(QTime::currentTime(), configuration.getHourStrokeColor(), configuration.getMinuteStrokeColor());
    timer->start(calculateTimeUntilNextMinuteChange());
}
