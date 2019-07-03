#include "ws2811sim.h"
#include <QDir>
#include <QColor>

const QString format = QString("R%1,G%2,B%3");

Ws2811Sim::Ws2811Sim(const quint16 numberOfLeds)
{
    for(quint16 iterator = 0; iterator < numberOfLeds; ++iterator)
    {
        ledstring.append(format.arg(QString::number(0)).arg(QString::number(0)).arg(QString::number(0)));
    }
    ledstringCache = ledstring;
}

Ws2811Sim::~Ws2811Sim()
{

}

void Ws2811Sim::renderPixels()
{
    ledstring = ledstringCache;
}

QStringList& Ws2811Sim::getLedString()
{
    return ledstring;
}

void Ws2811Sim::setPixel(const quint16 pixel, const QColor& color)
{
    QString colorAsString = format.arg(QString::number(color.red())).arg(QString::number(color.green())).arg(QString::number(color.blue()));
    ledstringCache.replace(pixel, colorAsString);
}
