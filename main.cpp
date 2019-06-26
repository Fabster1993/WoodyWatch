#include <QCoreApplication>
#include "ws2811impl.linux.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Ws2811Impl led;
    led.setLed();

    return a.exec();
}
