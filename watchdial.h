#ifndef WATCHDIAL_H
#define WATCHDIAL_H

#include <QObject>

class Ws2811Interface;

class WatchDial : public QObject
{
    Q_OBJECT
public:
    explicit WatchDial(const quint16 pixelPerMinuteStroke, const quint16 pixelPerHourStroke, Ws2811Interface* ledInterface);
    void showTimeOfDay(const QTime& timeOfDay);
    static quint16 getPixelQuantity(const quint16 pixelPerMinuteStroke, const quint16 pixelPerHourStroke);

signals:

public slots:

private:
    void showHours(const quint16 hours);
    void showMinutes(const quint16 minutes);
    quint16 from24hFormatToAMPM(quint16 hours);

    quint16 pixelPerMinuteStroke;
    quint16 pixelPerHourStroke;
    Ws2811Interface* ledInterface;
};

#endif // WATCHDIAL_H
