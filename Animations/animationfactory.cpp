#include "Animations/animationfactory.h"
#include "Animations/hourblinkanimation.h"
#include "Animations/increasingcircleanimation.h"
#include "Animations/runningdotanimation.h"

const QString formatting("%1\n");


Animation& AnimationFactory::create(const QString& name, WatchDial& watchDial)
{
    static HourBlinkAnimation defaultInstance(watchDial);
    if(name == HourBlinkAnimation::getName())
    {
        return defaultInstance;
    }
    if(name == IncreasingCircleAnimation::getName())
    {
        static IncreasingCircleAnimation instance(watchDial);
        return instance;
    }
    if(name == RunningDotAnimation::getName())
    {
        static RunningDotAnimation instance(watchDial);
        return instance;
    }
    return defaultInstance;
}

QString AnimationFactory::getAllAvailableAnimationNames()
{
    QString animationList;
    animationList += formatting.arg(HourBlinkAnimation::getName());
    animationList += formatting.arg(IncreasingCircleAnimation::getName());
    animationList += formatting.arg(RunningDotAnimation::getName());
    return animationList;
}
