#ifndef RUNNINGDOTANIMATION_H
#define RUNNINGDOTANIMATION_H

#include "Animations/animation.h"

class RunningDotAnimation : public Animation
{
    Q_OBJECT
public:
    explicit RunningDotAnimation(WatchDial& watchDial, QObject *parent = nullptr);
    virtual void play();
    static QString getName();
private:
    void lightsOn();
};

#endif // RUNNINGDOTANIMATION_H
