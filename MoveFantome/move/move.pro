TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        move.cpp

HEADERS += \
    move.h

include(../MinGL/mingl.pri)
