#ifndef WS2811IMPL_LINUX_H
#define WS2811IMPL_LINUX_H

#include "ws2811interface.h"

struct ws2811_channel_t;
struct ws2811_t;

class Ws2811Impl : public Ws2811Interface
{
public:
    Ws2811Impl(const quint16 numberOfPixel);
    ~Ws2811Impl();
    virtual void setPixel(const quint16 pixel, const QColor& color);
    virtual void renderPixels();
private:
    ws2811_channel_t* channel;
    ws2811_t* ledstring;
};

#endif // WS2811IMPL_LINUX_H
