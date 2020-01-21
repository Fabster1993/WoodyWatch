#ifndef HOURBLINKANIMATION_H
#define HOURBLINKANIMATION

#include "Animations/animation.h"


class HourBlinkAnimation : public Animation
{
    Q_OBJECT
public:
    explicit HourBlinkAnimation(WatchDial& watchDial, QObject *parent = nullptr);
    virtual void play();
    static QString getName();
private:
    void lightsOn();
};

#endif // HOURBLINKANIMATION
