#include "UnitTests/testws2811interface.h"
#include "ws2811interface.h"
#include "ws2811sim.h"
#include "UnitTests/Helper/csvreader.h"
#include <QDir>

void Ws2811InterfaceUT::initTestCase()
{

}

void Ws2811InterfaceUT::testRenderFirstPixelToRed()
{
    QString filepath = QDir::currentPath() + "/UnitTests/TestData/FirstPixelRed.csv";
    CsvReader csvReader = CsvReader(filepath);
    Ws2811Interface* ledInterface = new Ws2811Sim(3);

    ledInterface->setPixel(0, QColor(255, 0, 0));
    ledInterface->renderPixels();

    Ws2811Sim* interfaceSim = dynamic_cast<Ws2811Sim*>(ledInterface);
    QCOMPARE(interfaceSim->getLedString(), csvReader.getContent());
}

void Ws2811InterfaceUT::testRenderSecondPixelToBlue()
{
    QString filepath = QDir::currentPath() + "/UnitTests/TestData/SecondPixelBlue.csv";
    CsvReader csvReader = CsvReader(filepath);
    Ws2811Interface* ledInterface = new Ws2811Sim(3);

    ledInterface->setPixel(1, QColor(0, 0, 255));
    ledInterface->renderPixels();

    Ws2811Sim* interfaceSim = dynamic_cast<Ws2811Sim*>(ledInterface);
    QCOMPARE(interfaceSim->getLedString(), csvReader.getContent());
}

void Ws2811InterfaceUT::testLightsOffAfterRenderingEveryPixelToRed()
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
    ledInterface->lightsOff();

    Ws2811Sim* interfaceSim = dynamic_cast<Ws2811Sim*>(ledInterface);
    QCOMPARE(interfaceSim->getLedString(), csvReader.getContent());
}

void Ws2811InterfaceUT::cleanupTestCase()
{

}
