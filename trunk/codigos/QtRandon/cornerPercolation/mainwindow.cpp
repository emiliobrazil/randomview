#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdlib>

#include <QPushButton>
#include <QGridLayout>
#include <QtGui>


MainWindow::MainWindow( void )
{
    ui.setupUi(this);

    connect( ui.quitButton , SIGNAL( clicked() ) , qApp , SLOT( quit () ) );
    connect( ui.newButton , SIGNAL( clicked() ) , this , SLOT( startProcess() ) );
    connect( ui.scaleSpinBox , SIGNAL( valueChanged(int) ) , this , SLOT( changeScale(int) ) ) ;
    connect( ui.boxRadiusSpinBox , SIGNAL( valueChanged(int) ) , this , SLOT( changeRadius(int) ) ) ;
    connect( ui.probSpinBox, SIGNAL( valueChanged(double) ) , this , SLOT( changeRadius(double) ) ) ;

    startProcess();

}

MainWindow::~MainWindow()
{

}


void MainWindow::startProcess( void )
{
    probS = ui.probSpinBox->value();
    processRadius = (unsigned int)ui.boxRadiusSpinBox->value();

    process = PercolationProcess( processRadius , processRadius , probS );
}

void  MainWindow::changeScale( int S )
{
    // TODO
}

void  MainWindow::changeRadius( int R )
{
    processRadius = (unsigned int)R;
}

void  MainWindow::changeProb( double P )
{
    probS = P;
}
