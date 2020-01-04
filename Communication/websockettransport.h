#ifndef WEBSOCKETTRANSPORT_H
#define WEBSOCKETTRANSPORT_H

#include <QWebChannelAbstractTransport>

QT_BEGIN_NAMESPACE
class QWebSocket;
QT_END_NAMESPACE

class WebSocketTransport : public QWebChannelAbstractTransport
{
    Q_OBJECT
public:
    explicit WebSocketTransport(QWebSocket* socket);
    virtual ~WebSocketTransport() override;

    void sendMessage(const QJsonObject& message) override;

private slots:
    void textMessageReceived(const QString& message);

private:
    QWebSocket* socket;
};

#endif // WEBSOCKETTRANSPORT_H
