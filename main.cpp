#include <QCoreApplication>
#include <watch.h>
#include <ws2811impl.h>
#include <watchdial.h>


const quint16 pixelPerMinuteStroke = 1;
const quint16 pixelPerHourStroke = 4;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Ws2811Impl interface(WatchDial::getPixelQuantity(pixelPerMinuteStroke, pixelPerHourStroke));
    WatchDial watchDial(pixelPerMinuteStroke, pixelPerHourStroke, &interface);
    Watch watch(5000, &watchDial);

    return a.exec();
}
