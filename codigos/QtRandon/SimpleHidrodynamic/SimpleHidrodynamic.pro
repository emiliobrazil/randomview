# -------------------------------------------------
# Project created by QtCreator 2009-04-27T20:10:34
# -------------------------------------------------
QT += opengl \
    script
TARGET = SimpleHidrodynamic
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    random_functions.c \
    ParticlesCounter.cpp \
    HidrodinamicsSystem.cpp \
    HidrodinamicsParticles.cpp \
    Clocks.cpp
HEADERS += mainwindow.h \
    random_functions.h \
    primitive_types.h \
    primitive_const.h \
    ParticlesCounter.hpp \
    HidrodinamicsSystem.hpp \
    HidrodinamicsParticles.hpp \
    FDP.hpp \
    Clocks.hpp
FORMS += interface.ui
