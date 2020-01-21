#include "configuration.h"
#include <QXmlStreamWriter>
#include <QFile>
#include <QDir>

const QString rootElement = "configuration";
const QString hourColorElement = "hourColor";
const QString minuteColorElement = "minuteColor";
const QString redElement = "red";
const QString greenElement = "green";
const QString blueElement = "blue";
const QString animationElement = "animation";
const QString configurationFileName = "configuration.xml";

QColor Configuration::getHourStrokeColor() const
{
    return hourStrokeColor;
}

QColor Configuration::getMinuteStrokeColor() const
{
    return minuteStrokeColor;
}

QString Configuration::getAnimation() const
{
    return animation;
}

void Configuration::setHourStrokeColor(const QColor hourStrokeColor)
{
    this->hourStrokeColor = hourStrokeColor;
}

void Configuration::setMinuteStrokeColor(const QColor minuteStrokeColor)
{
    this->minuteStrokeColor = minuteStrokeColor;
}

void Configuration::setAnimation(const QString animationName)
{
    animation = animationName;
}

void Configuration::persist(const QString& configurationPath)
{
    QFile configurationFile(configurationPath + QDir::separator() + configurationFileName);
    if(configurationFile.open(QIODevice::WriteOnly))
    {
        QXmlStreamWriter stream(&configurationFile);
        stream.setAutoFormatting(true);
        stream.writeStartDocument();
        stream.writeStartElement(rootElement);
        stream.writeStartElement(hourColorElement);
        stream.writeTextElement(redElement, QString::number(hourStrokeColor.red()));
        stream.writeTextElement(greenElement, QString::number(hourStrokeColor.green()));
        stream.writeTextElement(blueElement, QString::number(hourStrokeColor.blue()));
        stream.writeEndElement(); // hourColorElement
        stream.writeStartElement(minuteColorElement);
        stream.writeTextElement(redElement, QString::number(minuteStrokeColor.red()));
        stream.writeTextElement(greenElement, QString::number(minuteStrokeColor.green()));
        stream.writeTextElement(blueElement, QString::number(minuteStrokeColor.blue()));
        stream.writeEndElement(); // minuteColorElement
        stream.writeTextElement(animationElement, animation);
        stream.writeEndElement(); // rootElement
        stream.writeEndDocument();
    }
    configurationFile.close();
}

Configuration Configuration::load(const QString &configurationPath)
{
    Configuration configuration;
    QFile configurationFile(configurationPath + QDir::separator() + configurationFileName);
    if(configurationFile.open(QIODevice::ReadOnly))
    {
        QXmlStreamReader stream(&configurationFile);
        while (!stream.atEnd())
        {
            if(stream.readNext() == QXmlStreamReader::StartElement)
            {
                if(stream.qualifiedName() == hourColorElement)
                {
                    QColor hourStrokeColor = loadColorFromStream(stream);
                    configuration.setHourStrokeColor(hourStrokeColor);
                }
                if(stream.qualifiedName() == minuteColorElement)
                {
                    QColor minuteStrokeColor = loadColorFromStream(stream);
                    configuration.setMinuteStrokeColor(minuteStrokeColor);
                }
                if(stream.qualifiedName() == animationElement)
                {
                    QString animationName = stream.readElementText();
                    configuration.setAnimation(animationName);
                }
            }
        }
    }
    configurationFile.close();
    return configuration;
}

QColor Configuration::loadColorFromStream(QXmlStreamReader& stream)
{
    QRgb color = 0;
    while (!stream.atEnd())
    {
        color = color << 8;
        stream.readNextStartElement();
        quint32 value = stream.readElementText().toUInt();
        color |= value;

        if(stream.qualifiedName() == blueElement) // as this is the last element
            break;
    }
    return QColor(color);
}
