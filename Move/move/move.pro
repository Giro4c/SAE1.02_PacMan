TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Pacman.cpp \
        main.cpp \
        move.cpp \
        yaml.cpp

HEADERS += \
    Pacman.h \
    move.h \
    yaml.h
