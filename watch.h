#ifndef WATCH_H
#define WATCH_H

#include <QObject>

class QTimer;
class QTime;
class WatchDial;
class Configuration;

class Watch : public QObject
{
    Q_OBJECT
public:
    explicit Watch(quint16 updateCycle, WatchDial* watchDial);
    ~Watch();
    void initialize();
    void configureWatchDial(const Configuration& configuration);
public slots:
    // temporary
    void setHourStrokeColor(quint32 hourStrokeColor);
private slots:
    void showTime();
private:
    QTimer* timer;
    WatchDial* watchDial;
};

#endif // WATCH_H
