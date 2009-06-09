#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdlib>

#include <QPushButton>
#include <QGridLayout>
#include <QtGui>


MainWindow::MainWindow( void )
{
    ui.setupUi(this);

    connect( ui.quitButton  , SIGNAL( clicked() ) , qApp , SLOT( quit () ) );

    viewer = new PathViewer;
    ui.spaceGrid->addWidget( viewer );

    Site tmp;

    for(int i = 0 ; i < 100 ; ++i )
    {
        int step = 1;

        step = ( (float) rand() ) / RAND_MAX > 1.0/2 ? 1 : -1;

        ( (float) rand() ) / RAND_MAX > 1.0/2 ? tmp.addX(step) : tmp.addY(step);

        this->path.add( tmp );

    }

    for( unsigned int i = 0 ;  i < path.size() ; ++i)
    {
        fprintf( stderr , "P%d = ( %d , %d )\n", i , path.getSite(i).X() , path.getSite(i).Y() );
    }

    // nao use printf's para debugar!!! :p
    if( path.isClosed() ) {
        fprintf( stderr , "The path is closed." );
    }


    this->viewer->addPath( path );
    this->viewer->draw( );
}

MainWindow::~MainWindow()
{

}
