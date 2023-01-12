TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        NosFiles/Pacman.cpp \
        NosFiles/collision.cpp \
        NosFiles/move.cpp \
        NosFiles/param.cpp \
        main.cpp
include ("MinGL2/mingl.pri")

HEADERS += \
    NosFiles/Pacman.h \
    NosFiles/collision.h \
    NosFiles/move.h \
    NosFiles/param.h \
    NosFiles/type.h

DISTFILES += \
    config.yaml
