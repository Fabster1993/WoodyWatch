#ifndef WATCH_H
#define WATCH_H

#include <QObject>

class QTimer;
class QTime;
class WatchDial;
class Configuration;
class Ws2811Interface;

class Watch : public QObject
{
    Q_OBJECT
public:
    Watch(const Watch&) = delete;
    void operator=(const Watch&) = delete;
    static Watch& getInstance();
    ~Watch();
    void initialize();
    void configureWatchDial(const Configuration& configuration);
    void setHourStrokeColor(quint32 hourStrokeColor);
    void setMinuteStrokeColor(quint32 minuteStrokeColor);
private slots:
    void showTime();
private:
    explicit Watch();
    static qint32 calculateNextTimerTimeout();
    QTimer* timer;
    WatchDial* watchDial;
    Ws2811Interface* ledInterface;
};

#endif // WATCH_H
