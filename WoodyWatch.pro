QT += gui testlib
QT += webchannel
QT += websockets
QT += core

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


HEADERS += \
    ws2811interface.h \
    watchdial.h \
    ws2811impl.h \
    watch.h \
    configuration.h \
    Communication/websocketclientwrapper.h \
    Communication/websockettransport.h \
    Communication/webchannel.h \
    Communication/webinterface.h \
    Animations/animation.h \
    Animations/animationfactory.h \
    Animations/hourblinkanimation.h \
    Animations/increasingcircleanimation.h \
    Animations/runningdotanimation.h \
    Animations/pingponganimation.h

SOURCES += \
    main.cpp \
    ws2811interface.cpp \
    watchdial.cpp \
    ws2811impl.cpp \
    watch.cpp \
    configuration.cpp \
    Communication/websocketclientwrapper.cpp \
    Communication/websockettransport.cpp \
    Communication/webchannel.cpp \
    Communication/webinterface.cpp \
    Animations/animation.cpp \
    Animations/animationfactory.cpp \
    Animations/hourblinkanimation.cpp \
    Animations/increasingcircleanimation.cpp \
    Animations/runningdotanimation.cpp \
    Animations/pingponganimation.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /home/pi/app
!isEmpty(target.path): INSTALLS += target

# install html client
webclient.path = /var/www/html
webclient.files = WebClient/*
INSTALLS += webclient

# add WS2811 lib as static dependency
unix:!macx: LIBS += -L$$PWD/Dependencies/WS2811/bin/ -lWS2811

INCLUDEPATH += $$PWD/Dependencies/WS2811/Headers
DEPENDPATH += $$PWD/Dependencies/WS2811/Headers

unix:!macx: PRE_TARGETDEPS += $$PWD/Dependencies/WS2811/bin/libWS2811.a
