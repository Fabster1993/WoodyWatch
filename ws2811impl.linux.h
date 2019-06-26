#ifndef WS2811IMPL_LINUX_H
#define WS2811IMPL_LINUX_H

#include <QObject>
#include "ws2811interface.h"

struct ws2811_channel_t;
struct ws2811_t;

class Ws2811Impl : public Ws2811Interface
{
public:
    Ws2811Impl();
    void setLed();
private:
    ws2811_channel_t* channel;
    ws2811_t* ledstring;
};

#endif // WS2811IMPL_LINUX_H
