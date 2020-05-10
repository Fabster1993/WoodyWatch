#ifndef PINGPONGANIMATION_H
#define PINGPONGANIMATION_H

#include "Animations/animation.h"

class PingPongAnimation : public Animation
{
    Q_OBJECT
public:
    explicit PingPongAnimation(WatchDial& watchDial, QObject *parent = nullptr);
    virtual void play();
    static QString getName();
private:
    void lightsOn();
};

#endif // PINGPONGANIMATION_H
