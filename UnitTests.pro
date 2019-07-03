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

win32:SOURCES += \
    UnitTests/Helper/csvreader.cpp \
    UnitTests/ws2811interfaceut.cpp \
    ws2811sim.cpp \
    ws2811interface.cpp \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /home/pi/app
!isEmpty(target.path): INSTALLS += target

win32:HEADERS += \
    UnitTests/Helper/csvreader.h \
    ws2811interface.h \
    ws2811sim.h

testdata.path = $$OUT_PWD/UnitTests/TestData/
testdata.files = UnitTests/TestData/*
INSTALLS += testdata
