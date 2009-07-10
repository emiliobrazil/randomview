#include "percolationshow.h"
#include <iostream>

PercolationShow::PercolationShow( QWidget *parent ) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void PercolationShow::drawAll( PercolationProcess& processNew , double scaleNew , bool isMovingNew , bool isDropingPathNew )
{
    process = processNew;
    isMoving = isMovingNew;
    isDropingPath = isDropingPathNew;
    if( isDropingPath ) this->setCursor(Qt::PointingHandCursor);
    if( isMoving ) this->setCursor(Qt::OpenHandCursor);
    scale = scaleNew;
    update();
}

void PercolationShow::clearPaths( void )
{
    paths.clear();
    update();
}

void PercolationShow::changeIsDropingPath( bool B )
{
    isDropingPath = B;
    if( isDropingPath ) this->setCursor(Qt::PointingHandCursor);
}


void PercolationShow::changeIsMoving( bool B )
{
    isMoving = B;
    if( isMoving ) this->setCursor(Qt::OpenHandCursor);
}

void PercolationShow::paintEvent( QPaintEvent *event )
{
    frameSize = this->size();

    int Rx = frameSize.width()/(2*scale);
    int Ry = frameSize.height()/(2*scale);

    std::cout << "PercolationShow::paintEvent( QPaintEvent *event )" << Rx << "  "<< Ry <<"  scale = " << scale << "   frameSize = " << frameSize.width() << "  " << frameSize.height() << std::endl;

    QPainter painter(this);
    PercolationDrawerQT drawertmp;
    drawertmp.setWindow( painter , frameSize.width() , frameSize.height() , -Rx , Rx , -Ry , Ry );
    transfor = drawertmp.getTransform();

//    drawPath( painter );

    drawertmp.drawSistemEdges( painter , process);

    painter.setPen( QPen( QBrush( Qt::magenta ), 0.3f ) );

    drawertmp.drawSistemSites( painter , process);

    painter.drawPoint( 0 , 0 );

}

void PercolationShow::mousePressEvent(QMouseEvent *event)
{
    QPoint o = event->pos();
    std::cout << o.x()<< " vv " << o.y() << std::endl;
    QTransform teste = transfor.inverted();
    QPoint p = teste.map( o );
    std::cout << p.x() << " xx " << p.y() << std::endl;

}

void PercolationShow::mouseMoveEvent(QMouseEvent *event)
{

}
