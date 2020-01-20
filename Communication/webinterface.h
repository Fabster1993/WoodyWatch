#ifndef WEBINTERFACE_H
#define WEBINTERFACE_H

#include <QObject>

class QWebSocketServer;
class WebSocketClientWrapper;
class WebChannel;

class WebInterface : public QObject
{
    Q_OBJECT
public:
    explicit WebInterface(QObject *parent = nullptr);
    ~WebInterface();

signals:

public slots:
    void setHourStrokeColor(quint32 color);
    void setMinuteStrokeColor(quint32 color);
    void showChimes();
private:
    QWebSocketServer* server;
    WebSocketClientWrapper* clientWrapper;
    WebChannel* webChannel;
};

#endif // WEBINTERFACE_H
