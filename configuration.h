#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QColor>

class Configuration
{
public:
    explicit Configuration( const QColor hourStrokeColor, const QColor minuteStrokeColor);
    Configuration();
    QColor getHourStrokeColor() const;
    QColor getMinuteStrokeColor() const;

private:
    QColor hourStrokeColor;
    QColor minuteStrokeColor;
};

#endif // CONFIGURATION_H
