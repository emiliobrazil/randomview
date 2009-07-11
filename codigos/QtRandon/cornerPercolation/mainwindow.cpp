#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdlib>
#include <iostream>

#include <QPushButton>
#include <QGridLayout>
#include <QtGui>


MainWindow::MainWindow( void )
{
    ui.setupUi(this);

    viewer = new PercolationShow( this );
    ui.spaceGrid->addWidget( viewer );

    connect( ui.quitButton , SIGNAL( clicked() ) , qApp , SLOT( quit () ) );
    connect( ui.newButton , SIGNAL( clicked() ) , this , SLOT( startProcess() ) );
    connect( ui.scaleSpinBox , SIGNAL( valueChanged(int) ) , this , SLOT( changeScale(int) ) ) ;
    connect( ui.boxRadiusSpinBox , SIGNAL( valueChanged(int) ) , this , SLOT( changeRadius(int) ) ) ;
    connect( ui.probSpinBox, SIGNAL( valueChanged(double) ) , this , SLOT( changeProb(double) ) ) ;
    connect( ui.moveButton, SIGNAL( clicked(bool) ), this , SLOT( changeIsMoving(bool)  ) );
    connect( ui.pathButton, SIGNAL( clicked(bool) ), this , SLOT( changeisDropingParticle(bool) ) );

    startProcess();

}

MainWindow::~MainWindow()
{

}

void MainWindow::startProcess( void )
{
    viewer->clearPaths();
    probS = ui.probSpinBox->value();
    processRadius = (unsigned int)ui.boxRadiusSpinBox->value();

    process = PercolationProcess( processRadius , processRadius , probS );

    drawSystem();
}

void  MainWindow::changeScale( int S )
{
    scale = S;
    viewer->changeScale( scale );
}

void  MainWindow::changeRadius( int R )
{
    processRadius = (unsigned int)R;
}

void  MainWindow::changeProb( double P )
{
    probS = P;
}

void MainWindow::changeIsMoving( bool B )
{
    viewer->changeIsMoving( B );
}

void MainWindow::changeisDropingParticle( bool B )
{
    viewer->changeisDropingParticle( B );
}

void MainWindow::drawSystem( void )
{
    scale = ui.scaleSpinBox->value();
    bool isMoving = ui.moveButton->isChecked();
    bool isDropingParticle = ui.pathButton->isChecked();
    viewer->drawAll( process , scale , isMoving , isDropingParticle );
}

void MainWindow::keyPressEvent ( QKeyEvent * event )
{
    switch ( event->key() )
    {
    case Qt::Key_Q:
        qApp->quit();
        break;
        default: break;
    }
}
