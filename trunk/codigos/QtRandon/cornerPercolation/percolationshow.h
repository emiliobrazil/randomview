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

    void drawAll( PercolationProcess& process , double scale , bool isMoving , bool isDropingPath );

public slots:
    void clearPaths( void );
    void changeIsMoving( bool B );
    void changeIsDropingPath( bool B );

protected:
    void paintEvent( QPaintEvent *event );
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


private:
    std::vector<Path> paths;
    Particle particle;
    PercolationProcess process;

    int scale;

    bool isMoving;
    bool isDropingPath;

    QSize frameSize;

    QTransform transfor;

    int dx , dy;

};

#endif // PERCOLATIONSHOW_H
