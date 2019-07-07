#ifndef TESTWS2811INTERFACE_H
#define TESTWS2811INTERFACE_H

#include <QtTest/QtTest>

class Ws2811InterfaceUT: public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void testRenderFirstPixelToRed();
    void testRenderSecondPixelToBlue();
    void testLightsOffAfterRenderingEveryPixelToRed();
    void cleanupTestCase();
};

#endif // TESTWS2811INTERFACE_H
