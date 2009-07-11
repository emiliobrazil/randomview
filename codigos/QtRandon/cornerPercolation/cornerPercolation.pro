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
    percolationdrawerqt.cpp \
    percolationshow.cpp \
    particle.cpp \
    random_functions.cpp
HEADERS += mainwindow.h \
    pathviewer.h \
    types.hpp \
    site.hpp \
    percolation_process.hpp \
    path.hpp \
    particle.hpp \
    edge.hpp \
    percolationdrawerqt.h \
    percolationshow.h \
    random_functions.h \
    primitive_types.h \
    primitive_const.h
FORMS += mainwindow.ui
