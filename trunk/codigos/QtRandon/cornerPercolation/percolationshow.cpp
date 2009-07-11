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
    dx = 0 ;
    dy = 0 ;
}

void PercolationShow::clearPaths( void )
{
    particles.clear();
    update();
}

void PercolationShow::changeisDropingParticle( bool B )
{
    isDropingParticle = B;
    isMoving = !B;

    if( isDropingParticle ) this->setCursor(Qt::PointingHandCursor);
}


void PercolationShow::changeIsMoving( bool B )
{
    isMoving = B;
    isDropingParticle = !B;

    if( isMoving ) this->setCursor(Qt::OpenHandCursor);
}

void PercolationShow::paintEvent( QPaintEvent *event )
{
    frameSize = this->size();

    int Rx = frameSize.width()/(2*scale);
    int Ry = frameSize.height()/(2*scale);

    QPainter painter(this);
    PercolationDrawerQT drawertmp;
    drawertmp.setWindow( painter , frameSize.width() , frameSize.height() , -Rx - dx , Rx - dx , -Ry - dy , Ry - dy );
    transfor = drawertmp.getTransform();

    painter.setPen( QPen( QBrush( Qt::blue ), 3.0/scale ) );
    drawPaths( painter );

    painter.setPen( QPen( QBrush( Qt::magenta ), 4.0/scale ) );
    painter.drawPoint( 0 , 0 );


    painter.setPen( QPen( QBrush( Qt::black ), 1/scale ) );
    drawertmp.drawSistemEdges( painter , process);
    drawertmp.drawSistemSites( painter , process);

}


void PercolationShow::mousePressEvent(QMouseEvent *event)
{
    oldPoint = event->pos();
    QTransform Ti = transfor.inverted();
    QPoint oI = Ti.map( oldPoint );
    if(isDropingParticle) dropParticle( oldPoint );
    if(isMoving)  this->setCursor(Qt::ClosedHandCursor);
    update();
}

void PercolationShow::mouseMoveEvent(QMouseEvent *event)
{
    if( event->buttons() == Qt::LeftButton && isMoving )
    {
        QPoint newPoint = event->pos();

        QTransform Ti = transfor.inverted();

        QPoint oI = Ti.map( oldPoint );
        QPoint nI = Ti.map( newPoint );

        dx += nI.x()-oI.x();
        dy += nI.y()-oI.y();

        oldPoint = newPoint;
        update();
    }
}

void PercolationShow::mouseReleaseEvent(QMouseEvent *event)
{
    if(isMoving) this->setCursor(Qt::OpenHandCursor);

}

void PercolationShow::dropParticle( QPoint start )
{
    std::cout << "void PercolationShow::dropParticle( QPoint start )" <<  std::endl;
    QTransform Ti = transfor.inverted();
    QPoint sI = Ti.map(start);
    Site startS( sI.x() , sI.y() );
    Particle tmpParticle( startS );
    tmpParticle.walk( process );
    particles.push_back(tmpParticle);
}

void PercolationShow::drawPaths( QPainter& painter )
{
    for( int i = 0 ; i < particles.size() ; ++i )
    {
        Particle partTMP = particles[i];
        std::vector<Path> pathsTmp = partTMP.getPaths();

        for( int j = 0 ; j < pathsTmp.size() ; ++j )
        {
            Path tmp = pathsTmp[j];
            PercolationDrawerQT drawertmp;
            drawertmp.drawPath( painter , pathsTmp[j] );
        }
    }
}
