#include "percolationshow.h"
#include <iostream>

PercolationShow::PercolationShow( QWidget *parent ) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void PercolationShow::drawAll( PercolationProcess& processNew , double scaleNew , bool isMovingNew , bool isDropingParticleNew )
{
    process = processNew;
    isMoving = isMovingNew;
    isDropingParticle = isDropingParticleNew;
    if( isDropingParticle ) this->setCursor(Qt::PointingHandCursor);
    if( isMoving ) this->setCursor(Qt::OpenHandCursor);
    scale = scaleNew;
    update();
}

void PercolationShow::clearPaths( void )
{
    paths.clear();
    update();
}

void PercolationShow::changeisDropingParticle( bool B )
{
    isDropingParticle = B;
    if( isDropingParticle ) this->setCursor(Qt::PointingHandCursor);
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
    oldPoint = event->pos();
    QTransform Ti = transfor.inverted();
    QPoint oI = Ti.map( oldPoint );
    if(isDropingParticle) dropParticle( oldPoint );

}

void PercolationShow::mouseMoveEvent(QMouseEvent *event)
{

}

void PercolationShow::dropParticle( QPoint start )
{

}

