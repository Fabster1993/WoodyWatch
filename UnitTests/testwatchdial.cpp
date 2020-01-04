#include "UnitTests/testwatchdial.h"
#include "ws2811sim.h"
#include "watchdial.h"
#include "UnitTests/Helper/csvreader.h"
#include <QDir>

void TestWatchDial::testShowTimeOfDay_data()
{
    QTest::addColumn<QString>("testDataFile");
    QTest::addColumn<QTime>("time");

    QTest::newRow("12h59") << QString(QDir::currentPath() + "/UnitTests/TestData/12h59.csv") << QTime(12,59);
    QTest::newRow("00h59") << QString(QDir::currentPath() + "/UnitTests/TestData/12h59.csv") << QTime(0,59);
    QTest::newRow("02h33") << QString(QDir::currentPath() + "/UnitTests/TestData/02h33.csv") << QTime(2,33);
    QTest::newRow("14h33") << QString(QDir::currentPath() + "/UnitTests/TestData/02h33.csv") << QTime(14,33);
    QTest::newRow("03h15") << QString(QDir::currentPath() + "/UnitTests/TestData/03h15.csv") << QTime(3,15);
    QTest::newRow("15h15") << QString(QDir::currentPath() + "/UnitTests/TestData/03h15.csv") << QTime(15,15);
}

void TestWatchDial::testShowTimeOfDay()
{
    QFETCH(QString, testDataFile);
    QFETCH(QTime, time);
    CsvReader csvReader = CsvReader(testDataFile);
    Ws2811Sim* interface = new Ws2811Sim(WatchDial::getPixelQuantity());
    WatchDial watchDial(interface);

    watchDial.showTimeOfDay(time);

    QCOMPARE(interface->getLedString(), csvReader.getContent());
}

void TestWatchDial::testSetTwoTimesOfDayInSuccession()
{
    QTime firstTimeOfDay(12,58);
    QTime secondTimeOfDay(12,59);
    QString testDataFile(QDir::currentPath() + "/UnitTests/TestData/12h59.csv");
    CsvReader csvReader = CsvReader(testDataFile);
    Ws2811Sim* interface = new Ws2811Sim(WatchDial::getPixelQuantity());
    WatchDial watchDial(interface);

    watchDial.showTimeOfDay(firstTimeOfDay);
    watchDial.showTimeOfDay(secondTimeOfDay);

    QCOMPARE(interface->getLedString(), csvReader.getContent());
}
