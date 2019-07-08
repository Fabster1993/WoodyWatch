#include "ws2811interface.h"
#include <QColor>

Ws2811Interface::Ws2811Interface(quint16 numberOfPixel) :
    numberOfPixel(numberOfPixel)
{

}

Ws2811Interface::~Ws2811Interface()
{

}

void Ws2811Interface::resetAllPixel()
{
    QColor dark(0, 0, 0);
    for(quint16 pixel = 0; pixel < numberOfPixel; ++pixel)
    {
        setPixel(pixel, dark);
    }
}
