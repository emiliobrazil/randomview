#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_interface.h"
#include "HidrodinamicsSystem.hpp"


#include <QtGui/QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( void );
    ~MainWindow();

private slots:
    void pause( void );
    void start( void );
    void reset( void );


private:
    Ui::MainWindow ui;

    ParticlesCounter counter;
    real t, alpha;
    FDP function;
    uint32 numberOfPartices;

    bool isPaused;
    bool isRuning;
    bool isReseted;

};

#endif // MAINWINDOW_H
