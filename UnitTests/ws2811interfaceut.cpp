#include <QtTest/QtTest>
#include "ws2811interface.h"
#include "ws2811sim.h"
#include "UnitTests/Helper/csvreader.h"
#include <QDir>

class Ws2811InterfaceUT: public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void testSetPixel_data();
    void testSetPixel();
    void testSetFirstPixelToRed();
    void testSetSecondPixelToBlue();
    void cleanupTestCase();
};

void Ws2811InterfaceUT::initTestCase()
{

}

void Ws2811InterfaceUT::testSetPixel_data()
{
    QTest::addColumn<QString>("filepath");
    QTest::addColumn<quint16>("numberOfPixel");
    QTest::addColumn<QColor>("color");
    QTest::addColumn<quint16>("pixelOfInterest");

    QTest::newRow("first pixel red") << QDir::currentPath() + "/UnitTests/TestData/FirstPixelRed.csv" << 3 << QColor(255, 0, 0) << 0;
    QTest::newRow("second pixel blue") << QDir::currentPath() + "/UnitTests/TestData/SecondPixelBlue.csv" << 3 << QColor(0, 0, 255) << 1;
}

void Ws2811InterfaceUT::testSetPixel()
{
    QFETCH(QString, filepath);
    QFETCH(quint16, numberOfPixel);
    QFETCH(QColor, color);
    QFETCH(quint16, pixelOfInterest);
    Ws2811Interface* ledInterface = new Ws2811Sim(numberOfPixel);
    CsvReader csvReader = CsvReader(filepath);

    ledInterface->setPixel(pixelOfInterest, color);
    ledInterface->renderPixels();

    Ws2811Sim* interfaceSim = dynamic_cast<Ws2811Sim*>(ledInterface);
    QCOMPARE(interfaceSim->getLedString(), csvReader.getContent());
}

void Ws2811InterfaceUT::testSetFirstPixelToRed()
{
    QString filepath = QDir::currentPath() + "/UnitTests/TestData/FirstPixelRed.csv";
    CsvReader csvReader = CsvReader(filepath);
    Ws2811Interface* ledInterface = new Ws2811Sim(3);

    ledInterface->setPixel(0, QColor(255, 0, 0));
    ledInterface->renderPixels();

    Ws2811Sim* interfaceSim = dynamic_cast<Ws2811Sim*>(ledInterface);
    QCOMPARE(interfaceSim->getLedString(), csvReader.getContent());
}

void Ws2811InterfaceUT::testSetSecondPixelToBlue()
{
    QString filepath = QDir::currentPath() + "/UnitTests/TestData/SecondPixelBlue.csv";
    CsvReader csvReader = CsvReader(filepath);
    Ws2811Interface* ledInterface = new Ws2811Sim(3);

    ledInterface->setPixel(1, QColor(0, 0, 255));
    ledInterface->renderPixels();

    Ws2811Sim* interfaceSim = dynamic_cast<Ws2811Sim*>(ledInterface);
    QCOMPARE(interfaceSim->getLedString(), csvReader.getContent());
}

void Ws2811InterfaceUT::cleanupTestCase()
{

}

QTEST_GUILESS_MAIN(Ws2811InterfaceUT)
#include "ws2811interfaceut.moc"
