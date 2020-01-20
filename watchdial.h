#ifndef WATCHDIAL_H
#define WATCHDIAL_H

#include <QObject>

class Ws2811Interface;

class WatchDial : public QObject
{
    Q_OBJECT
public:
    explicit WatchDial(Ws2811Interface* ledInterface);
    void showTimeOfDay(const QTime& timeOfDay, const QColor& hourStrokeColor, const QColor& minuteStrokeColor);
    static quint16 getPixelQuantity();
    void setHourPixel(const quint16 hour, const QColor& color);
    void setMinutePixel(const quint16 minute, const QColor& color);
    static quint16 from24hFormatToAmPm(quint16 hours);
    quint16 getHourStartPixel(const quint16 hour);
    quint16 getMinuteStartPixel(const quint16 minute);
    void setPixelRange(const quint16 startPixel, const quint16 endPixel, const QColor& color);
    void render();
    void resetPixels();
private:
    Ws2811Interface* ledInterface;

};

#endif // WATCHDIAL_H
