#include "ws2811impl.h"
#include "WS2811/ws2811.h"
#include <QtDebug>
#include <QColor>

const quint16 pwmGpioPin = 18;
const quint32 frequency = 800000;
const quint16 dmaNumber = 10;
const quint16 brightness = 128;

Ws2811Impl::Ws2811Impl(const quint16 numberOfPixel) :
    Ws2811Interface(numberOfPixel) ,
    channel(nullptr),
    ledstring(nullptr)
{
    channel = new ws2811_channel_t;
    channel->gpionum = pwmGpioPin;
    channel->invert = 0;
    channel->strip_type = WS2811_STRIP_GRB;
    channel->count = numberOfPixel;
    channel->brightness = brightness;

    ledstring = new ws2811_t;
    ledstring->freq = frequency;
    ledstring->dmanum = dmaNumber;
    ledstring->channel[0] = *channel;

    ws2811_return_t return_value = ws2811_init(ledstring);
    if(return_value != WS2811_SUCCESS)
    {
        qDebug() << "ws2811_init failed: " + QString(ws2811_get_return_t_str(return_value));
    }
}

Ws2811Impl::~Ws2811Impl()
{
    delete channel;
    channel = nullptr;

    ws2811_fini(ledstring);
    delete ledstring;
    ledstring = nullptr;
}

void Ws2811Impl::setPixel(const quint16 pixel, const QColor& color)
{
    ledstring->channel[0].leds[pixel] = color.rgb();
}

void Ws2811Impl::renderPixels()
{
    ws2811_render(ledstring);
}
