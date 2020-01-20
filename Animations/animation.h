#ifndef CHIMES_H
#define CHIMES_H

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
};

#endif // CHIMES_H
