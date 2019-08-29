#ifndef WATCH_H
#define WATCH_H

#include <QObject>

class QTimer;
class QTime;
class WatchDial;

class Watch : public QObject
{
    Q_OBJECT
public:
    explicit Watch(quint16 updateCycle, WatchDial* watchDial);
    ~Watch();

private slots:
    void showTime();
private:
    QTimer* timer;
    WatchDial* watchDial;
};

#endif // WATCH_H
