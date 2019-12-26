#include "webchannel.h"
#include "Communication/websockettransport.h"

WebChannel::WebChannel() :
    QWebChannel ()
{

}

void WebChannel::connectTo(WebSocketTransport* transport)
{
    QWebChannel::connectTo(transport);
}
