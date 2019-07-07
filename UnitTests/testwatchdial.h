#ifndef TESTWATCHDIAL_H
#define TESTWATCHDIAL_H

#include <QtTest/QtTest>

class TestWatchDial: public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void testShowTimeOfDay();
    void cleanupTestCase();
};

#endif // TESTWATCHDIAL_H
