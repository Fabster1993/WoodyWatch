window.onload = initializeWebChannel;

function initializeWebChannel () {
    var baseUrl = "ws://192.168.1.117:443/";
    var socket = new WebSocket(baseUrl);

    socket.onclose = function () {
        console.error("web channel closed");
    };
    socket.onerror = function (error) {
        console.error("web channel error: " + error);
    };
    socket.onopen = function () {
        new QWebChannel(socket, function (channel) {
            // make core object accessible globally
            window.watch = channel.objects.watch;
        });
    }
} 

