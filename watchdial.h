#ifndef WATCHDIAL_H
#define WATCHDIAL_H

#include <QObject>
#include "configuration.h"

class Ws2811Interface;

class WatchDial : public QObject
{
    Q_OBJECT
public:
    explicit WatchDial(const quint16 pixelPerMinuteStroke, const quint16 pixelPerHourStroke, Ws2811Interface* ledInterface);
    void showTimeOfDay(const QTime& timeOfDay);
    static quint16 getPixelQuantity(const quint16 pixelPerMinuteStroke, const quint16 pixelPerHourStroke);
    void configure(const Configuration configuration);

signals:

public slots:

private:
    void setHourPixel(const quint16 hours);
    void setMinutePixel(const quint16 minutes);
    static quint16 from24hFormatToAmPm(quint16 hours);
    quint16 getHourStartPixel(const quint16 hours);
    quint16 getMinuteStartPixel(const quint16 minutes);
    void setPixelRange(const quint16 startPixel, const quint16 endPixel, const QColor& color);

    quint16 pixelPerMinuteStroke;
    quint16 pixelPerHourStroke;
    Ws2811Interface* ledInterface;
    Configuration configuration;
};

#endif // WATCHDIAL_H
