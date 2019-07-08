#ifndef TESTWS2811INTERFACE_H
#define TESTWS2811INTERFACE_H

#include <QtTest/QtTest>

class TestWs2811Interface: public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void testRenderSinglePixel_data();
    void testRenderSinglePixel();
    void testLightsOffAfterRenderingEveryPixelToRed();
    void cleanupTestCase();
};

#endif // TESTWS2811INTERFACE_H
