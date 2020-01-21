#include "testconfiguration.h"
#include "configuration.h"
#include <QDir>

void TestConfiguration::testSaveAndLoadConfiguration()
{
    Configuration expectedConfiguration;
    expectedConfiguration.setHourStrokeColor(QColor(50, 100, 200));
    expectedConfiguration.setMinuteStrokeColor(QColor(40, 80, 160));
    expectedConfiguration.setAnimation("Animation");

    expectedConfiguration.persist(QDir::currentPath());
    Configuration loadedConfiguration = Configuration::load(QDir::currentPath());

    QCOMPARE(expectedConfiguration.getHourStrokeColor(), loadedConfiguration.getHourStrokeColor());
    QCOMPARE(expectedConfiguration.getMinuteStrokeColor(), loadedConfiguration.getMinuteStrokeColor());
    QCOMPARE(expectedConfiguration.getAnimation(), loadedConfiguration.getAnimation());
}
