#include "Animations/animation.h"
#include <QTimer>
#include "watchdial.h"

Animation::Animation(WatchDial& watchDial, QObject *parent)
    : QObject(parent),
      timer(new QTimer()),
      watchDial(watchDial)
{
    connect(timer, &QTimer::timeout, this, &Animation::play);
}

Animation::~Animation()
{
    delete timer;
    timer = nullptr;
}
