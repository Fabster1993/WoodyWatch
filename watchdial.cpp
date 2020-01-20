#include "watchdial.h"
#include <ws2811interface.h>
#include <QTime>
#include <QColor>

const quint16 pixelPerMinuteStroke = 1;
const quint16 pixelPerHourStroke = 4;

WatchDial::WatchDial(Ws2811Interface* ledInterface)
    : QObject(nullptr)
    , ledInterface(ledInterface)
{

}

void WatchDial::showTimeOfDay(const QTime& timeOfDay, const QColor& hourStrokeColor, const QColor& minuteStrokeColor)
{
    resetPixels();
    setHourPixel(static_cast<quint16>(timeOfDay.hour()), hourStrokeColor);
    setMinutePixel(static_cast<quint16>(timeOfDay.minute()), minuteStrokeColor);
    render();
}

quint16 WatchDial::getPixelQuantity()
{
    return 12 * pixelPerHourStroke + 48 * pixelPerMinuteStroke;
}

void WatchDial::setHourPixel(const quint16 hour, const QColor& color)
{
    quint16 startPixel = getHourStartPixel(hour);
    quint16 endPixel = startPixel + pixelPerHourStroke - 1;
    setPixelRange(startPixel, endPixel, color);
}

void WatchDial::setMinutePixel(const quint16 minute, const QColor& color)
{
    quint16 startPixel = getMinuteStartPixel(minute);
    quint16 endPixel = startPixel + pixelPerMinuteStroke - 1;
    setPixelRange(startPixel, endPixel, color);
}

quint16 WatchDial::from24hFormatToAmPm(quint16 hour)
{
    if(hour >= 12)
    {
        return hour - 12;
    }
    return hour;
}

quint16 WatchDial::getHourStartPixel(const quint16 hour)
{
    quint16 hoursInAmPmFormat = from24hFormatToAmPm(hour);
    return hoursInAmPmFormat * (pixelPerHourStroke + 4 * pixelPerMinuteStroke);
}

quint16 WatchDial::getMinuteStartPixel(const quint16 minute)
{
    quint16 hourStrokesBetweenZeroAndCurrentMinuteStroke = (minute + 4) / 5;
    return hourStrokesBetweenZeroAndCurrentMinuteStroke * pixelPerHourStroke + (minute - hourStrokesBetweenZeroAndCurrentMinuteStroke) * pixelPerMinuteStroke;
}

void WatchDial::setPixelRange(const quint16 startPixel, const quint16 endPixel, const QColor& color)
{
    for(quint16 pixel = startPixel; pixel <= endPixel; ++pixel)
    {
        ledInterface->setPixel(pixel, color);
    }
}

void WatchDial::render()
{
    ledInterface->renderPixels();
}

void WatchDial::resetPixels()
{
    ledInterface->resetAllPixel();
}
