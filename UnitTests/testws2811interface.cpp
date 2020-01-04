#include "UnitTests/testws2811interface.h"
#include "ws2811interface.h"
#include "ws2811sim.h"
#include "UnitTests/Helper/csvreader.h"
#include <QDir>

void TestWs2811Interface::testRenderSinglePixel_data()
{
    QTest::addColumn<QString>("testDataFile");
    QTest::addColumn<QColor>("color");
    QTest::addColumn<quint16>("pixel");

    QTest::newRow("first pixel red") << QString(QDir::currentPath() + "/UnitTests/TestData/FirstPixelRed.csv") << QColor(255, 0, 0) << quint16(0);
    QTest::newRow("second pixel blue") << QString(QDir::currentPath() + "/UnitTests/TestData/SecondPixelBlue.csv") << QColor(0, 0, 255) << quint16(1);
}

void TestWs2811Interface::testRenderSinglePixel()
{
    QFETCH(QString, testDataFile);
    QFETCH(QColor, color);
    QFETCH(quint16, pixel);

    CsvReader csvReader = CsvReader(testDataFile);
    Ws2811Interface* ledInterface = new Ws2811Sim(3);

    ledInterface->setPixel(pixel, color);
    ledInterface->renderPixels();

    Ws2811Sim* interfaceSim = dynamic_cast<Ws2811Sim*>(ledInterface);
    QCOMPARE(interfaceSim->getLedString(), csvReader.getContent());
}

void TestWs2811Interface::testLightsOffAfterRenderingEveryPixelToRed()
{
    QString filepath = QDir::currentPath() + "/UnitTests/TestData/LightsOff.csv";
    CsvReader csvReader = CsvReader(filepath);
    const quint16 numberOfPixel = 3;
    Ws2811Interface* ledInterface = new Ws2811Sim(numberOfPixel);

    for(quint16 pixel = 0; pixel < numberOfPixel; ++pixel)
    {
        ledInterface->setPixel(pixel, QColor(255, 0, 0));
    }
    ledInterface->renderPixels();
    ledInterface->resetAllPixel();
    ledInterface->renderPixels();

    Ws2811Sim* interfaceSim = dynamic_cast<Ws2811Sim*>(ledInterface);
    QCOMPARE(interfaceSim->getLedString(), csvReader.getContent());
}
