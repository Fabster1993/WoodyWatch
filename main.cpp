#include <QCoreApplication>
#include "watch.h"
#include "Communication/webinterface.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Watch::getInstance().initialize();

    WebInterface webInterface;

    return a.exec();
}
