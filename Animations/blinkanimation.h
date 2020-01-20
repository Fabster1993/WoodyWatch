#ifndef BLINKCHIMES_H
#define BLINKCHIMES_H

#include "Animations/animation.h"


class BlinkAnimation : public Animation
{
    Q_OBJECT
public:
    explicit BlinkAnimation(WatchDial& watchDial, QObject *parent = nullptr);
    virtual void play();
    static QString getName();
private:
    void lightsOff();
    void lightsOn();
    quint16 counter;
};

#endif // BLINKCHIMES_H
