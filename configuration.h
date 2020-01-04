#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QColor>

class QXmlStreamReader;

class Configuration
{
public:
    Configuration();
    QColor getHourStrokeColor() const;
    QColor getMinuteStrokeColor() const;
    void setHourStrokeColor(const QColor hourStrokeColor);
    void setMinuteStrokeColor(const QColor minuteStrokeColor);
    void persist(const QString& configurationPath);
    static Configuration load(const QString& configurationPath);

private:
    QColor hourStrokeColor;
    QColor minuteStrokeColor;

    static QColor loadColorFromStream(QXmlStreamReader& stream);
};

#endif // CONFIGURATION_H
