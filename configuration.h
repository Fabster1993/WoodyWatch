#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QColor>

class QXmlStreamReader;

class Configuration
{
public:
    QColor getHourStrokeColor() const;
    QColor getMinuteStrokeColor() const;
    QString getAnimation() const;
    void setHourStrokeColor(const QColor hourStrokeColor);
    void setMinuteStrokeColor(const QColor minuteStrokeColor);
    void setAnimation(const QString animationName);
    void persist(const QString& configurationPath);
    static Configuration load(const QString& configurationPath);

private:
    QColor hourStrokeColor;
    QColor minuteStrokeColor;
    QString animation;

    static QColor loadColorFromStream(QXmlStreamReader& stream);
};

#endif // CONFIGURATION_H
