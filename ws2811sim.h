#ifndef WS2811SIM_H
#define WS2811SIM_H

#include "ws2811interface.h"
#include <QFile>

class Ws2811Sim : public Ws2811Interface
{
public:
    Ws2811Sim(const quint16 numberOfLeds);
    ~Ws2811Sim();
    virtual void setPixel(const quint16 pixel, const QColor& color);
    virtual void renderPixels();
    QStringList& getLedString();
private:
    QStringList ledstring;
    QStringList ledstringCache;
};

#endif // WS2811SIM_H
