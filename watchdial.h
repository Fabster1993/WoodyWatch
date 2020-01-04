#ifndef WATCHDIAL_H
#define WATCHDIAL_H

#include <QObject>
#include "configuration.h"

class Ws2811Interface;

class WatchDial : public QObject
{
    Q_OBJECT
public:
    explicit WatchDial(Ws2811Interface* ledInterface);
    void showTimeOfDay(const QTime& timeOfDay);
    static quint16 getPixelQuantity();
    Configuration getConfiguration() const;
    void setConfiguration(Configuration configuration);

private:
    void setHourPixel(const quint16 hour);
    void setMinutePixel(const quint16 minute);
    static quint16 from24hFormatToAmPm(quint16 hours);
    quint16 getHourStartPixel(const quint16 hour);
    quint16 getMinuteStartPixel(const quint16 minute);
    void setPixelRange(const quint16 startPixel, const quint16 endPixel, const QColor& color);

    Ws2811Interface* ledInterface;
    Configuration configuration;
};

#endif // WATCHDIAL_H
