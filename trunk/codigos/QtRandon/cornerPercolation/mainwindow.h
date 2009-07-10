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

private:
    Ui::MainWindow ui;

    PercolationShow *viewer;

    std::vector<Path> paths;

    PercolationProcess process;
    unsigned int processRadius;
    double probS;
    unsigned int scale;

};

#endif // MAINWINDOW_H
