#ifndef WATCH_H
#define WATCH_H

#include <QObject>
#include "configuration.h"

class QTimer;
class QTime;
class WatchDial;
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
    void setHourStrokeColor(quint32 hourStrokeColor);
    void setMinuteStrokeColor(quint32 minuteStrokeColor);
    void setAnimation(const QString animationName);
    QColor getHourStrokeColor() const;
    QColor getMinuteStrokeColor() const;
    QString getAnimationName();
    void startAnimation();
    void showAnimation(const QString animation);
    void showTimeOfDay();
private slots:
    void onMinutePassed();
private:
    explicit Watch();
    static qint32 calculateTimeUntilNextMinuteChange();
    QTimer* timer;
    WatchDial* watchDial;
    Ws2811Interface* ledInterface;
    Configuration configuration;
};

#endif // WATCH_H
