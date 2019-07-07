#ifndef WS2811INTERFACE_H
#define WS2811INTERFACE_H

#include <QObject>

class Ws2811Interface
{
public:
    Ws2811Interface(quint16 numberOfPixel);
    virtual ~Ws2811Interface();
    virtual void setPixel(const quint16 pixel, const QColor& color) = 0;
    virtual void renderPixels() = 0;
    virtual void lightsOff();
private:
    quint16 numberOfPixel;
};

#endif // WS2811INTERFACE_H
