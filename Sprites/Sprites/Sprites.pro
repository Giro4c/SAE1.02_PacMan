TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        sprites_et_map_bp-intersection.cpp
include(MinGL2/mingl.pri)
