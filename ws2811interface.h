#ifndef WS2811INTERFACE_H
#define WS2811INTERFACE_H

#include <QObject>

class Ws2811Interface
{
public:
    Ws2811Interface();
    virtual ~Ws2811Interface();
    virtual void setPixel(const quint16 pixel, const QColor& color) = 0;
    virtual void renderPixels() = 0;
};

#endif // WS2811INTERFACE_H
