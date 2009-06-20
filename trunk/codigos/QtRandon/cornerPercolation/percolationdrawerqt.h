#ifndef PERCOLATIONDRAWERQT_H
#define PERCOLATIONDRAWERQT_H

#include <QWidget>
#include <QPainter>

#include "path.hpp"
#include "edge.hpp"
#include "percolation_process.hpp"

class PercolationDrawerQT
{
public:
    PercolationDrawerQT();

    void setWindow( QPainter &painter , int windowWidh , int windowHeight ,
                                        int systemStartX , int systemEndX ,
                                        int systemStartY , int systemEndY );
    void setWindow( QPainter &painter );
    void setWindow( QPainter &painter , QTransform& tranform );

    QTransform& getWindowTranform( void );
    void setWindowTranform( const QTransform& tranform );

    void drawPath( QPainter &painter , Path& path);
    void drawSistemEdges( QPainter &painter , PercolationProcess& process );
    void drawSistemSites( QPainter &painter , PercolationProcess& process );

private:
    QTransform tranform;

};

#endif // PERCOLATIONDRAWERQT_H
