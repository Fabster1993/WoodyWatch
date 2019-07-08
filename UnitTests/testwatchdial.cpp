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

void TestWatchDial::testShowTimeOfDay_data()
{
    QTest::addColumn<QString>("testDataFile");
    QTest::addColumn<QTime>("time");

    QTest::newRow("12h59") << QString(QDir::currentPath() + "/UnitTests/TestData/12h59.csv") << QTime(12,59);
}

void TestWatchDial::testShowTimeOfDay()
{
    QFETCH(QString, testDataFile);
    QFETCH(QTime, time);

    CsvReader csvReader = CsvReader(testDataFile);
    Ws2811Sim* interface = new Ws2811Sim(WatchDial::getPixelQuantity(pixelPerMinuteStroke, pixelPerHourStroke));
    WatchDial watchdial(pixelPerMinuteStroke, pixelPerHourStroke, interface);

    watchdial.showTimeOfDay(time);

    QCOMPARE(interface->getLedString(), csvReader.getContent());
}

void TestWatchDial::cleanupTestCase()
{

}
