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
    PercolationProcess process;
    QPainter painter(this);
    PercolationDrawerQT drawertmp;
    drawertmp.setWindow( painter , frameSize.width() , frameSize.height() , -15 , 15 , -5 , 5 );

//    drawPath( painter );

    drawertmp.drawSistemEdges( painter , process);
    drawertmp.drawSistemSites( painter , process);

    painter.setPen( QPen( QBrush( Qt::green ), 0.2f ) );
    painter.drawPoint( 0 , 0 );

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
