#ifndef INCREASINGCIRCLEANIMATION_H
#define INCREASINGCIRCLEANIMATION_H

#include "Animations/animation.h"


class IncreasingCircleAnimation : public Animation
{
    Q_OBJECT
public:
    explicit IncreasingCircleAnimation(WatchDial& watchDial, QObject *parent = nullptr);
    virtual void play();
    static QString getName();
private:
    void lightsOn();
};

#endif // INCREASINGCIRCLEANIMATION_H
