#include "pathviewer.h"

#include<QPainter>
#include<QPolygon>

PathViewer::PathViewer( QWidget *parent ) : QWidget(parent)
{

}

void PathViewer::draw()
{
    update();
}

void PathViewer::paintEvent( QPaintEvent *event )
{
    qreal scale = 30.0;
    QPainter painter(this);
    painter.setWindow( -500 , -500 , 1000 , 1000 );
    painter.setTransform( QTransform( scale , 0 , 0 , 0 , -scale , 0 , -200 , -30 , 1 ) );
    drawPath( painter );
}

void PathViewer::drawPath( QPainter &painter )
{
    int numberOfPath = this->allPath.size();
    for( int i = 0 ; i < numberOfPath ; i++ )
    {
        drawPath( painter , this->allPath[i] );
    }
    update();
}

void PathViewer::drawPath( QPainter &painter , Path &path )
{
    QPolygon poligonTMP;
    int numberOfSites = path.size();
    for ( int i = 0 ; i < numberOfSites ; i++)
    {
        poligonTMP.push_back( QPoint(path.getSite( i ).X() , path.getSite( i ).Y() ) );
    }
    painter.drawPolyline( poligonTMP );
    update();
}

void PathViewer::addPath( Path& path )
{
    this->allPath.push_back(path);
}
