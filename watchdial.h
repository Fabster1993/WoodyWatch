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
    void setHourPixel(const quint16 hours);
    void setMinutePixel(const quint16 minutes);
    static quint16 from24hFormatToAMPM(quint16 hours);
    quint16 getHourStartPixel(const quint16 hours);
    quint16 getMinuteStartPixel(const quint16 minutes);
    void setPixelRange(const quint16 startPixel, const quint16 endPixel, const QColor& color);

    quint16 pixelPerMinuteStroke;
    quint16 pixelPerHourStroke;
    Ws2811Interface* ledInterface;
};

#endif // WATCHDIAL_H
