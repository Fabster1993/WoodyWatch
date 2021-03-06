QT += gui testlib

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    UnitTests/Helper/csvreader.cpp \
    ws2811sim.cpp \
    ws2811interface.cpp \
    watchdial.cpp \
    UnitTests/testwatchdial.cpp \
    UnitTests/main.cpp \
    UnitTests/testws2811interface.cpp \
    configuration.cpp \
    UnitTests/testconfiguration.cpp

HEADERS += \
    UnitTests/Helper/csvreader.h \
    ws2811interface.h \
    ws2811sim.h \
    watchdial.h \
    UnitTests/testwatchdial.h \
    UnitTests/testws2811interface.h \
    configuration.h \
    UnitTests/testconfiguration.h

testdata.path = $$OUT_PWD/UnitTests/TestData/
testdata.files = UnitTests/TestData/*
INSTALLS += testdata
