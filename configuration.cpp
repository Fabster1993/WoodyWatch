#include "configuration.h"

const QColor minuteStrokeColorDefault = QColor(0, 0, 255); // blue
const QColor hourStrokeColorDefault = QColor(255, 0, 0); // red

Configuration::Configuration(const QColor hourStrokeColor, const QColor minuteStrokeColor) :
      hourStrokeColor(hourStrokeColor),
      minuteStrokeColor(minuteStrokeColor)
{

}

Configuration::Configuration() :
      hourStrokeColor(hourStrokeColorDefault),
      minuteStrokeColor(minuteStrokeColorDefault)
{

}

QColor Configuration::getHourStrokeColor() const
{
    return hourStrokeColor;
}

QColor Configuration::getMinuteStrokeColor() const
{
    return minuteStrokeColor;
}
