# -------------------------------------------------
# Project created by QtCreator 2009-05-20T00:26:12
# -------------------------------------------------
QT += opengl \
    svg
TARGET = cornerPercolation
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    pathviewer.cpp \
    site.cpp \
    percolation_process.cpp \
    path.cpp \
    edge.cpp \
    percolationdrawerqt.cpp
HEADERS += mainwindow.h \
    pathviewer.h \
    types.hpp \
    site.hpp \
    percolation_process.hpp \
    path.hpp \
    particle.hpp \
    edge.hpp \
    percolationdrawerqt.h
FORMS += mainwindow.ui
LIBS += -llua5.1

OTHER_FILES += \
    rule.lua \
    init.lua
