#include "watchdial.h"
#include <ws2811interface.h>
#include <QTime>

WatchDial::WatchDial(const quint16 pixelPerMinuteStroke, const quint16 pixelPerHourStroke, Ws2811Interface* ledInterface)
    : QObject(nullptr)
    , pixelPerMinuteStroke(pixelPerMinuteStroke)
    , pixelPerHourStroke(pixelPerHourStroke)
    , ledInterface(ledInterface)
{

}

void WatchDial::showTimeOfDay(const QTime& timeOfDay)
{
    showHours(static_cast<quint16>(timeOfDay.hour()));
    showMinutes(static_cast<quint16>(timeOfDay.minute()));
}

quint16 WatchDial::getPixelQuantity(const quint16 pixelPerMinuteStroke, const quint16 pixelPerHourStroke)
{
    return 12 * pixelPerHourStroke + 48 * pixelPerMinuteStroke;
}

void WatchDial::showHours(const quint16 hours)
{
    quint16 hoursInAmPmFormat = from24hFormatToAMPM(hours);
}

void WatchDial::showMinutes(const quint16 minutes)
{

}

quint16 WatchDial::from24hFormatToAMPM(quint16 hours)
{
    if(hours >= 12)
    {
        return hours - 12;
    }
    return hours;
}
