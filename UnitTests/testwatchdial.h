#ifndef TESTWATCHDIAL_H
#define TESTWATCHDIAL_H

#include <QtTest/QtTest>

class TestWatchDial: public QObject
{
    Q_OBJECT

private slots:
    void testShowTimeOfDay_data();
    void testShowTimeOfDay();
    void testSetTwoTimesOfDayInSuccession();
};

#endif // TESTWATCHDIAL_H
