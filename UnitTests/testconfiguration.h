#ifndef TESTCONFIGURATION_H
#define TESTCONFIGURATION_H

#include <QtTest/QtTest>

class TestConfiguration : public QObject
{
    Q_OBJECT
private slots:
    void testSaveAndLoadConfiguration();
};

#endif // TESTCONFIGURATION_H
