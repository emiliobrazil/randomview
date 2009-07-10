#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QtGui/QMainWindow>

#include "percolationshow.h"

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
    void startProcess( void );
    void changeScale( int S );
    void changeRadius( int R );
    void changeProb( double P );
    void changeIsMoving( bool B );
    void changeisDropingParticle( bool B );

private:
    void drawSystem( void );
    void keyPressEvent ( QKeyEvent * event );


private:
    Ui::MainWindow ui;

    PercolationShow *viewer;

    PercolationProcess process;

    unsigned int processRadius;
    double probS;
    unsigned int scale;

};

#endif // MAINWINDOW_H
