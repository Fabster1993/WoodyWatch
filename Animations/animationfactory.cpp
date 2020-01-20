#include "Animations/animationfactory.h"
#include "Animations/blinkanimation.h"


Animation &AnimationFactory::create(const QString& name, WatchDial &watchDial)
{
    (void)name; // currently unused
    static BlinkAnimation instance(watchDial);
    return instance;
}
