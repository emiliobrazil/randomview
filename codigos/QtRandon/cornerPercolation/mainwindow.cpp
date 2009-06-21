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

    this->path.add( tmp );

    tmp.addX(1)  ;this->path.add( tmp ); tmp.addY(1); this->path.add( tmp );
    tmp.addX(1)  ;this->path.add( tmp ); tmp.addY(1);this->path.add( tmp );
    tmp.addX(-1) ;this->path.add( tmp ); tmp.addY(1);this->path.add( tmp );
    tmp.addX(-1) ;this->path.add( tmp ); tmp.addY(1);this->path.add( tmp );
    tmp.addX(-1) ;this->path.add( tmp ); tmp.addY(-1);this->path.add( tmp );
    tmp.addX(-1) ;this->path.add( tmp ); tmp.addY(1);this->path.add( tmp );
    tmp.addX(-1) ;this->path.add( tmp ); tmp.addY(1);this->path.add( tmp );
    tmp.addX(-1) ;this->path.add( tmp ); tmp.addY(-1);this->path.add( tmp );
    tmp.addX(-1) ;this->path.add( tmp ); tmp.addY(1);this->path.add( tmp );
        

    this->viewer->addPath( path );

    tmp.setX(0) ; tmp.setY(1);

    Path p2( tmp );
    tmp.addX(-1)  ; p2.add( tmp ); tmp.addY(1); p2.add( tmp );
    tmp.addX(1)  ; p2.add( tmp ); tmp.addY(-1);p2.add( tmp );

    this->viewer->addPath( p2 );

    tmp.setX(-10) ; tmp.setY(-10);

    Path p3( tmp );
    for( int i = 0 ; i < 50 ; ++i)
    {
        tmp.addX(1)  ; p3.add( tmp ); tmp.addY(1); p3.add( tmp );
    }
        this->viewer->addPath( p3 );

    this->viewer->draw( );
}

MainWindow::~MainWindow()
{

}
