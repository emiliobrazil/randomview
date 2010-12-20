#include "counterviewer.h"

CounterViewer::CounterViewer( QWidget *parent ) : QWidget(parent)
{

}

void CounterViewer::paintEvent( QPaintEvent *event )
{
    Q_UNUSED(event);
    QPainter painter( this );
    drawCounter( painter );
}

void CounterViewer::draw( ParticlesCounter counter )
{
    this->aCounter = counter;
    update();
}

void CounterViewer::draw(  FDP function  )
{
    this->aFunction = function;
}


void CounterViewer::drawCounter( QPainter &painter )
{
    int marginHeight = 50;
    int maxWidth = this->width();
    int maxHeigth = this->height() - 2*marginHeight ;
    int numberOfSites = this->aCounter.size();

    real delta = (real)maxWidth/(real)numberOfSites;

    painter.setPen( QPen( QBrush( Qt::darkGreen ), 6.0f ) );
    for( int i = 0 ; i < numberOfSites ; ++i)
    {
        int dX = (int)( delta * i );
        int dY = (int)( maxHeigth *( 1.0 - aCounter.get(i) ) ) + marginHeight;
//        int dY = (int)( maxHeigth *( aCounter.get(i) ) ) + marginHeight;
        painter.drawPoint( dX , dY );
    }

    QPolygon functionPolyline;
    for( int i = 0 ; i < numberOfSites+1 ; ++i )
    {
        int dX = (int)( delta * i );
        int dY = (int)( maxHeigth *( 1.0 - aFunction.eval( i / (real)(numberOfSites-1)) ) ) + marginHeight;
        functionPolyline.push_back( QPoint( dX , dY ) );
    }

    painter.setPen( QPen( QBrush( Qt::darkRed ), 2.0f ) );
    painter.drawPolyline( functionPolyline );

}
