#ifndef PERCOLATIONSHOW_H
#define PERCOLATIONSHOW_H

#include <QWidget>
#include <QtGui>
#include<QPainter>

#include "percolationdrawerqt.h"
#include "path.hpp"
#include "particle.hpp"

class PercolationShow : public QWidget
{
public:
    PercolationShow( QWidget *parent = 0 );

    void drawAll( PercolationProcess& process , double scale , bool isMoving , bool isDropingParticle );

    void changeScale( double s );

public slots:
    void clearPaths( void );
    void changeIsMoving( bool B );
    void changeisDropingParticle( bool B );

protected:
    void paintEvent( QPaintEvent *event );
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void dropParticle( QPoint start );
    void drawPaths(  QPainter& painter );

private:
    std::vector<Particle> particles;
    PercolationProcess process;

    int scale;

    bool isMoving;
    bool isDropingParticle;

    QSize frameSize;

    QTransform transfor;

    int dx , dy;

    QPoint oldPoint;

};

#endif // PERCOLATIONSHOW_H
