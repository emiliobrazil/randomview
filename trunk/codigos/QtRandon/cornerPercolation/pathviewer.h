#ifndef PATHVIEWER_H
#define PATHVIEWER_H

#include <QWidget>
#include <QtGui>
#include <QPainter>

#include "percolationdrawerqt.h"

#include "path.hpp"

class PathViewer : public QWidget
{
public:
    PathViewer( QWidget *parent = 0 );

    void addPath( Path& path );

    void draw ( void );

    void setSize( QSize size ) { this->frameSize = size ;}

private:
    void paintEvent( QPaintEvent *event );

    void drawPath( QPainter &painter );

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    QSize frameSize;

    QTransform transfor;

    PercolationProcess process;


    std::vector<Path> allPath;
};

#endif // PATHVIEWER_H
