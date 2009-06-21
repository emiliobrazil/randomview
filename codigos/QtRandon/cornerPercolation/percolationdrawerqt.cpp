#include "percolationdrawerqt.h"

PercolationDrawerQT::PercolationDrawerQT()
{
    // the transformation is started with the identity
}

void PercolationDrawerQT::setWindow( QPainter &painter , int windowWidh , int windowHeight ,
                                     int systemStartX , int systemEndX ,
                                     int systemStartY , int systemEndY )
{
    int systemWidh   = systemEndX - systemStartX;
    int systemHeight = systemEndY - systemStartY;

    qreal widhFactor   = (qreal)(windowWidh)/(qreal)(systemWidh);
    qreal heightFactor = (qreal)(windowHeight)/(qreal)(systemHeight);

    qreal scale = (widhFactor<heightFactor)? widhFactor : heightFactor ;

    this->transform.scale( scale , -scale );
    this->transform.translate( -systemStartX , systemStartY );

    painter.setTransform( this->transform );
}

void PercolationDrawerQT::setWindow( QPainter &painter )
{
    painter.setTransform( this->transform );
}

void PercolationDrawerQT::setWindow( QPainter &painter , QTransform& externTransform )
{
    this->transform = externTransform;
    painter.setTransform( this->transform );
}

QTransform& PercolationDrawerQT::getTransform( void )
{
    return this->transform;
}

void PercolationDrawerQT::setTransform( const QTransform& externTransform )
{
    this->transform = externTransform;
}

void PercolationDrawerQT::drawPath( QPainter& painter , QPolygon& path )
{
    painter.drawPolyline( path );
}

void PercolationDrawerQT::drawPath( QPainter& painter , Path& path )
{
    QPolygon poligonTMP;
    int numberOfSites = path.size();
     fprintf(stderr, "PercolationDrawerQT::drawPath path.size() %d\n", path.size());

    for ( int i = 0 ; i < numberOfSites ; i++)
    {
        poligonTMP.push_back( QPoint(path.getSite( i ).X() , path.getSite( i ).Y() ) );
    }
    painter.drawPolyline( poligonTMP );
}

void PercolationDrawerQT::drawSistemEdges( QPainter& painter , PercolationProcess& process )
{

}


void PercolationDrawerQT::drawSistemSites( QPainter& painter , PercolationProcess& process )
{

}




