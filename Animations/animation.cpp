#include "Animations/animation.h"
#include <QTimer>
#include "watchdial.h"
#include "watch.h"

Animation::Animation(WatchDial& watchDial, QObject *parent)
    : QObject(parent),
      timer(new QTimer()),
      watchDial(watchDial),
      counter(0)
{
    connect(timer, &QTimer::timeout, this, &Animation::play);
    connect(this, &Animation::animationFinished, &Watch::getInstance(), &Watch::showTimeOfDay);
}

Animation::~Animation()
{
    delete timer;
    timer = nullptr;
}

void Animation::lightsOff()
{
    watchDial.resetPixels();
    watchDial.render();
}

void Animation::finishAnimation()
{
    counter = 0;
    timer->stop();
    emit animationFinished();
}
