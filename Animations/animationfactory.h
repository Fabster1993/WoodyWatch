#ifndef ANIMATIONFACTORY_H
#define ANIMATIONFACTORY_H

class Animation;
class QString;
class WatchDial;

class AnimationFactory
{
public:
    static Animation& create(const QString& name, WatchDial& watchDial);
    static QString getAllAvailableAnimationNames();
};

#endif // ANIMATIONFACTORY_H
