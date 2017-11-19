TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lncurses

SOURCES += src/main.cpp \
    src/rectangle.cpp \
    src/output.cpp \
    src/text.cpp \
    src/input.cpp

HEADERS += \
    include/rectangle.h \
    include/utylitys.h \
    include/output.h \
    include/text.h \
    include/input.h
