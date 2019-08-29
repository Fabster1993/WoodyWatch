#include "watchdial.h"
#include <ws2811interface.h>
#include <QTime>
#include <QColor>

const QColor minuteStrokeColor = QColor(0, 0, 255);
const QColor hourStrokeColor = QColor(255, 0, 0);

WatchDial::WatchDial(const quint16 pixelPerMinuteStroke, const quint16 pixelPerHourStroke, Ws2811Interface* ledInterface)
    : QObject(nullptr)
    , pixelPerMinuteStroke(pixelPerMinuteStroke)
    , pixelPerHourStroke(pixelPerHourStroke)
    , ledInterface(ledInterface)
{

}

void WatchDial::showTimeOfDay(const QTime& timeOfDay)
{
    ledInterface->resetAllPixel();
    setHourPixel(static_cast<quint16>(timeOfDay.hour()));
    setMinutePixel(static_cast<quint16>(timeOfDay.minute()));
    ledInterface->renderPixels();
}

quint16 WatchDial::getPixelQuantity(const quint16 pixelPerMinuteStroke, const quint16 pixelPerHourStroke)
{
    return 12 * pixelPerHourStroke + 48 * pixelPerMinuteStroke;
}

void WatchDial::setHourPixel(const quint16 hours)
{
    quint16 startPixel = getHourStartPixel(hours);
    quint16 endPixel = startPixel + pixelPerHourStroke - 1;
    setPixelRange(startPixel, endPixel, hourStrokeColor);
}

void WatchDial::setMinutePixel(const quint16 minutes)
{
    quint16 startPixel = getMinuteStartPixel(minutes);
    quint16 endPixel = startPixel + pixelPerMinuteStroke - 1;
    setPixelRange(startPixel, endPixel, minuteStrokeColor);
}

quint16 WatchDial::from24hFormatToAMPM(quint16 hours)
{
    if(hours >= 12)
    {
        return hours - 12;
    }
    return hours;
}

quint16 WatchDial::getHourStartPixel(const quint16 hours)
{
    quint16 hoursInAmPmFormat = from24hFormatToAMPM(hours);
    return hoursInAmPmFormat * (pixelPerHourStroke + 4 * pixelPerMinuteStroke);
}

quint16 WatchDial::getMinuteStartPixel(const quint16 minutes)
{
    quint16 hourStrokesBetweenZeroAndCurrentMinuteStroke = (minutes + 4) / 5;
    return hourStrokesBetweenZeroAndCurrentMinuteStroke * pixelPerHourStroke + (minutes - hourStrokesBetweenZeroAndCurrentMinuteStroke) * pixelPerMinuteStroke;
}

void WatchDial::setPixelRange(const quint16 startPixel, const quint16 endPixel, const QColor& color)
{
    for(quint16 pixel = startPixel; pixel <= endPixel; ++pixel)
    {
        ledInterface->setPixel(pixel, color);
    }
}
