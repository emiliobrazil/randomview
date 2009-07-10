#include "percolationdrawerqt.h"

PercolationDrawerQT::PercolationDrawerQT()
{
    // the transformation is started with the identity
    widh = 60; heiht = 60; startX = -30;   startY = -30;
}

void PercolationDrawerQT::setWindow( QPainter &painter ,
                                     int windowWidh   , int windowHeight ,
                                     int systemStartX , int systemEndX   ,
                                     int systemStartY , int systemEndY   )
{

    int systemWidh   = systemEndX - systemStartX;
    int systemHeight = systemEndY - systemStartY;

    qreal widhFactor   = (qreal)(windowWidh)/(qreal)(systemWidh);
    qreal heightFactor = (qreal)(windowHeight)/(qreal)(systemHeight);

    widh = systemWidh;
    heiht = systemHeight;
    startX = systemStartX;
    startY = systemStartY;

    scale = (widhFactor<heightFactor)? widhFactor : heightFactor ;

    this->transform.scale( scale , -scale );
    this->transform.translate( -systemStartX ,  -systemEndY );

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

    for ( int i = 0 ; i < numberOfSites ; i++)
    {
        poligonTMP.push_back( QPoint(path.getSite( i ).X() , path.getSite( i ).Y() ) );
    }
    painter.drawPolyline( poligonTMP );
}

void PercolationDrawerQT::drawSistemEdges( QPainter& painter , PercolationProcess& process )
{
    for( int i = 0 ; i < widh + 10 ; ++i )
    {
        for( int j = 0 ; j < heiht + 10 ; ++j )
        {
            int tmpX = i + startX - 5;
            int tmpY = j + startY - 5;
            bool drw;

            Site sTmp( tmpX , tmpY );

            if( process.inBox(sTmp) )
            {
                drw = process.isOpen( Edge( sTmp , H ) );
                if(drw) painter.drawLine( QPoint(tmpX,tmpY) , QPoint(tmpX+1,tmpY) );

                drw = process.isOpen( Edge( sTmp , V ) );
                if(drw) painter.drawLine( QPoint(tmpX,tmpY) , QPoint(tmpX,tmpY+1) );
            }
        }
    }
}


void PercolationDrawerQT::drawSistemSites( QPainter& painter , PercolationProcess& process )
{
    QPen oldPen = painter.pen();
    double sizeBrush = 4.0f/scale ;
    for( int i = 0 ; i < widh + 10 ; ++i )
    {
        for( int j = 0 ; j < heiht + 10 ; ++j )
        {
            int tmpX = i + startX - 5;
            int tmpY = j + startY - 5;

            bool otherColor;

            Site sTmp( tmpX , tmpY );

            if( process.inBox(sTmp) && scale > 5 )
            {
                otherColor = process.isOpen( sTmp  );
                QColor colorTmp;
                colorTmp  = (otherColor) ? Qt::darkGreen : Qt::darkRed ;
                painter.setPen( QPen( QBrush( colorTmp ), sizeBrush ) );
                painter.drawPoint( QPoint(tmpX,tmpY) );
            }
        }
    }
    painter.setPen( oldPen );
}



