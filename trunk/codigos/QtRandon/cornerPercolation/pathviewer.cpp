#include "pathviewer.h"

#include "percolationdrawerqt.h"

#include<QPainter>
#include<QPolygon>

PathViewer::PathViewer( QWidget *parent ) : QWidget(parent)
{
    this->frameSize = this->size();
}

void PathViewer::draw()
{
    update();
}

void PathViewer::paintEvent( QPaintEvent *event )
{
//    qreal scale = 30.0;
    QPainter painter(this);
//    painter.setTransform( QTransform( scale , 0 , 0 , 0 , -scale , 0 , 10*scale , 10*scale , 1 ) );
    PercolationDrawerQT drawertmp;
    drawertmp.setWindow( painter , frameSize.width() , frameSize.height() , -14 , 20 , -14 , 20 );
    drawPath( painter );
}

void PathViewer::drawPath( QPainter &painter )
{
    PercolationDrawerQT drawertmp;
    for( int i = 0 ; i < allPath.size() ; ++i)
    {
        drawertmp.drawPath( painter , this->allPath[i] );
    }

}


void PathViewer::addPath( Path& path )
{
    this->allPath.push_back(path);
}
