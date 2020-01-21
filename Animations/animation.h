#ifndef ANIMATION_H
#define ANIMATION_H

#include <QObject>

class WatchDial;
class QTimer;

class Animation : public QObject
{
    Q_OBJECT
public:
    explicit Animation(WatchDial& watchDial, QObject *parent = nullptr);
    virtual ~Animation();
    virtual void play() = 0;
protected:
    QTimer* timer;
    WatchDial& watchDial;
    quint16 counter;

    void lightsOff();
    void finishAnimation();
signals:
    void animationFinished();
};

#endif // ANIMATION_H
