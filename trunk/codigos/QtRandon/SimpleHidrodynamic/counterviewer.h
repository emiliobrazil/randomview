#ifndef COUNTERVIEWER_H
#define COUNTERVIEWER_H

#include <QWidget>
#include <QImage>
#include <QPoint>
#include <QPointF>
#include <QKeyEvent>
#include <QtGui>
#include <QColor>


#include "HidrodinamicsSystem.hpp"


class CounterViewer : public QWidget
{
public:
    CounterViewer( QWidget *parent = 0 ) ;

    void draw( ParticlesCounter counter  );
    void draw(  FDP function  );
    void setFunc( FDP function  ) { aFunction = function ;}

private:
    void paintEvent( QPaintEvent *event );
    void drawCounter( QPainter &painter );

    ParticlesCounter aCounter;
    FDP aFunction;
};

#endif // COUNTERVIEWER_H
