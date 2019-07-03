#ifndef WATCHDIAL_H
#define WATCHDIAL_H

#include <QObject>

class WatchDial : public QObject
{
    Q_OBJECT
public:
    explicit WatchDial(QObject *parent = nullptr);

signals:

public slots:

private:
    quint16 pixelPerMinuteStroke;
    quint16 pixelPerHourStroke;

};

#endif // WATCHDIAL_H
