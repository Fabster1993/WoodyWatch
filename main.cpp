#include <QCoreApplication>
#include <watch.h>
#include <ws2811impl.h>
#include <watchdial.h>

#include <QtWebSockets/QtWebSockets>
#include "Communication/websocketclientwrapper.h"
#include "Communication/webchannel.h"
#include "Communication/websockettransport.h"

const quint16 pixelPerMinuteStroke = 1;
const quint16 pixelPerHourStroke = 4;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Ws2811Impl interface(WatchDial::getPixelQuantity(pixelPerMinuteStroke, pixelPerHourStroke));
    WatchDial watchDial(pixelPerMinuteStroke, pixelPerHourStroke, &interface);
    Watch watch(5000, &watchDial);

    // Web stuff
    QWebSocketServer server(QStringLiteral("QWebChannel Standalone Example Server"), QWebSocketServer::NonSecureMode);

    if (!server.listen(QHostAddress::Any, 443)) {
        qDebug() << server.error();
        qFatal("Failed to open web socket server.");
        return 1;
    }
    qDebug() << server.serverAddress();

    WebSocketClientWrapper clientWrapper(&server);

    WebChannel webChannel;
    QObject::connect(&clientWrapper, &WebSocketClientWrapper::clientConnected,
                     &webChannel, &WebChannel::connectTo);
    webChannel.registerObject("watch", &watch);

    return a.exec();
}
