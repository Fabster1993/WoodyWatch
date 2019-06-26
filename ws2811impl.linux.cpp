#include "ws2811impl.linux.h"
#include "WS2811/ws2811.h"
#include <QtDebug>

Ws2811Impl::Ws2811Impl() :
    channel(nullptr),
    ledstring(nullptr)
{
    channel = new ws2811_channel_t;
    channel->gpionum = 18;
    channel->invert = 0;
    channel->strip_type = WS2811_STRIP_GRB;
    channel->count = 120; // number of leds
    channel->brightness = 128;

    ledstring = new ws2811_t;
    ledstring->freq = 800000;
    ledstring->dmanum = 10;
    ledstring->channel[0] = *channel;

    ws2811_return_t return_value = ws2811_init(ledstring);
    if(return_value != WS2811_SUCCESS)
    {
        qDebug() << "ws2811_init failed: " + QString(ws2811_get_return_t_str(return_value));
    }

}

void Ws2811Impl::setLed()
{
    ledstring->channel[0].leds[0] = 0x80AAC000;
    ledstring->channel[0].leds[1] = 0x80AAC000;
    ledstring->channel[0].leds[2] = 0x80AAC000;
    ledstring->channel[0].leds[3] = 0x80AAC000;
    ledstring->channel[0].leds[4] = 0x80AAC000;
    ledstring->channel[0].leds[5] = 0x80AAC000;
    ws2811_render(ledstring);
}
