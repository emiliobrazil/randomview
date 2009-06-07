#include "mainwindow.h"
#include "ui_mainwindow.h"

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
        this->path.add( tmp );
        tmp.addX( -1 );
        this->path.add( tmp );
        tmp.addY( -1 );
    }

    for( unsigned int i = 0 ;  i < path.size() ; ++i)
    {
        fprintf( stderr , "P%d = ( %d , %d )\n", i , path.getSite(i).X() , path.getSite(i).Y() );
    }


    this->viewer->addPath( path );
    this->viewer->draw( );
}

MainWindow::~MainWindow()
{

}
