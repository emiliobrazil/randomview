#include "pathviewer.h"

#include <iostream>

#include <QtGui>

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
    PercolationDrawerQT drawertmp;
    drawertmp.setWindow( painter , frameSize.width() , frameSize.height() , -15 , 15 , -5 , 5 );

    transfor = drawertmp.getTransform();

//    drawPath( painter );

    drawertmp.drawSistemEdges( painter , process);
    drawertmp.drawSistemSites( painter , process);

    painter.setPen( QPen( QBrush( Qt::magenta ), 0.3f ) );
    painter.drawPoint( 0 , 0 );

}

void PathViewer::drawPath( QPainter &painter )
{
    PercolationDrawerQT drawertmp;
    for( unsigned int i = 0 ; i < allPath.size() ; ++i)
    {
        drawertmp.drawPath( painter , this->allPath[i] );
    }

}


void PathViewer::addPath( Path& path )
{
    this->allPath.push_back(path);
}


void PathViewer::mousePressEvent(QMouseEvent *event)
{
    QPoint o = event->pos();
    std::cout << o.x()<< " vv " << o.y() << std::endl;
    QTransform teste = transfor.inverted();
    QPoint p = teste.map( o );
    std::cout << p.x() << " xx " << p.y() << std::endl;

}

void PathViewer::mouseMoveEvent(QMouseEvent *event)
{

}

