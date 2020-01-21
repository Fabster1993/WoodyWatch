#ifndef TESTWATCHDIAL_H
#define TESTWATCHDIAL_H

#include <QtTest/QtTest>

class TestWatchDial: public QObject
{
    Q_OBJECT

private slots:
    void testShowTime_data();
    void testShowTime();
    void testSetTwoTimesOfDayInSuccession();
};

#endif // TESTWATCHDIAL_H
