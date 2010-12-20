# -------------------------------------------------
# Project created by QtCreator 2009-04-27T20:10:34
# -------------------------------------------------
QT += opengl \
    script
TARGET = SimpleHidrodynamic
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    ParticlesCounter.cpp \
    HidrodinamicsSystem.cpp \
    HidrodinamicsParticles.cpp \
    Clocks.cpp \
    counterviewer.cpp \
    random_functions.cpp
HEADERS += mainwindow.h \
    primitive_types.h \
    primitive_const.h \
    ParticlesCounter.hpp \
    HidrodinamicsSystem.hpp \
    HidrodinamicsParticles.hpp \
    FDP.hpp \
    Clocks.hpp \
    counterviewer.h \
    random_functions.h
FORMS += interface.ui
