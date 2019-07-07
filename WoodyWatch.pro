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

HEADERS += \
    ws2811interface.h \
    watchdial.h \
    WS2811/clk.h \
    WS2811/dma.h \
    WS2811/gpio.h \
    WS2811/mailbox.h \
    WS2811/pcm.h \
    WS2811/pwm.h \
    WS2811/rpihw.h \
    WS2811/ws2811.h \
    ws2811impl.h \

SOURCES += \
    main.cpp \
    ws2811interface.cpp \
    watchdial.cpp \
    WS2811/dma.c \
    WS2811/mailbox.c \
    WS2811/pcm.c \
    WS2811/pwm.c \
    WS2811/rpihw.c \
    WS2811/ws2811.c \
    ws2811impl.cpp \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /home/pi/app
!isEmpty(target.path): INSTALLS += target
