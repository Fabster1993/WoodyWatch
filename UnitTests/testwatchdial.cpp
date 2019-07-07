#include "UnitTests/testwatchdial.h"
#include "ws2811sim.h"
#include "watchdial.h"
#include "UnitTests/Helper/csvreader.h"
#include <QDir>

const quint16 pixelPerMinuteStroke = 1;
const quint16 pixelPerHourStroke = 4;

void TestWatchDial::initTestCase()
{

}

void TestWatchDial::testShowTimeOfDay()
{
    QString filepath = QDir::currentPath() + "/UnitTests/TestData/FirstPixelRed.csv";
    CsvReader csvReader = CsvReader(filepath);
    Ws2811Sim* interface = new Ws2811Sim(WatchDial::getPixelQuantity(pixelPerMinuteStroke, pixelPerHourStroke));
    WatchDial watchdial(pixelPerMinuteStroke, pixelPerHourStroke, interface);
    watchdial.showTimeOfDay(QTime(12,59));
    QCOMPARE(interface->getLedString(), csvReader.getContent());
}

void TestWatchDial::cleanupTestCase()
{

}
