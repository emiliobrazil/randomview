#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_interface.h"
#include "HidrodinamicsSystem.hpp"
#include "counterviewer.h"


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
    void setMaxIteration( int mI );
    void setNunberOfSites( int noS );
    void setAlpha( double a );
    void setT( double tl );
    void changeInitialFunc( int index );

signals:
    void sendIteration( int itr );

private:
    Ui::MainWindow ui;

    ParticlesCounter counter;
    real t, alpha;
    uint32 numberOfSites , numberOfIterations , maxIteration ;
    CounterViewer *CV;

    bool isPaused;
    bool isRuning;
    bool isReseted;

    FDP_FUNC initialFunc ;

};

#endif // MAINWINDOW_H
