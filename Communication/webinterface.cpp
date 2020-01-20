#include "webinterface.h"
#include <QtWebSockets/QtWebSockets>
#include "Communication/websocketclientwrapper.h"
#include "Communication/webchannel.h"
#include "Communication/websockettransport.h"
#include "watch.h"

WebInterface::WebInterface(QObject *parent) :
    QObject(parent),
    server(nullptr),
    clientWrapper(nullptr),
    webChannel(new WebChannel())
{
    server = new QWebSocketServer(QStringLiteral("WebChannel Server"), QWebSocketServer::NonSecureMode);

    if (!server->listen(QHostAddress::Any, 443)) {
        qDebug() << server->error();
        qFatal("Failed to open web socket server.");
    }

    qDebug() << server->serverAddress();
    clientWrapper = new WebSocketClientWrapper(server);
    QObject::connect(clientWrapper, &WebSocketClientWrapper::clientConnected,
                     webChannel, &WebChannel::connectTo);
    webChannel->registerObject("watch", this);
}

WebInterface::~WebInterface()
{
    if(server != nullptr)
    {
        delete server;
        server = nullptr;
    }
    if(clientWrapper != nullptr)
    {
        delete clientWrapper;
        clientWrapper = nullptr;
    }
    if(webChannel != nullptr)
    {
        delete webChannel;
        webChannel = nullptr;
    }
}

void WebInterface::setHourStrokeColor(quint32 color)
{
    qDebug() << color;
    Watch::getInstance().setHourStrokeColor(color);
}

void WebInterface::setMinuteStrokeColor(quint32 color)
{
    Watch::getInstance().setMinuteStrokeColor(color);
}

void WebInterface::showChimes()
{
    Watch::getInstance().showAnimation();
}
