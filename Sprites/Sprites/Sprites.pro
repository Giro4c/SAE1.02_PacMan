TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Complements/game.cpp \
        Complements/params.cpp \
        main.cpp
include(MinGL2/mingl.pri)

DISTFILES += \
    configmap.yaml

HEADERS += \
    Complements/game.h \
    Complements/params.h \
    Complements/type.h
