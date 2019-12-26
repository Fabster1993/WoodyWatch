#ifndef WEBCHANNEL_H
#define WEBCHANNEL_H

#include <QtWebChannel/QWebChannel>

class WebSocketTransport;

class WebChannel : public QWebChannel
{
public:
    WebChannel();
public slots:
    void connectTo(WebSocketTransport* transport);
};

#endif // WEBCHANNEL_H
