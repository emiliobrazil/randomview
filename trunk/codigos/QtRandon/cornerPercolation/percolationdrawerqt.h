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
    PercolationDrawerQT( void );

    void setWindow( QPainter& painter , int windowWidh , int windowHeight ,
                                        int systemStartX , int systemEndX ,
                                        int systemStartY , int systemEndY );
    void setWindow( QPainter& painter );
    void setWindow( QPainter& painter , QTransform& transform );

    QTransform& getTransform( void );
    void setTransform( const QTransform& transform );

    void drawPath( QPainter& painter , QPolygon& path );
    void drawPath( QPainter& painter , Path& path );

    void drawSistemEdges( QPainter& painter , PercolationProcess& process );

    void drawSistemSites( QPainter& painter , PercolationProcess& process );

private:
    QTransform transform;


};

#endif // PERCOLATIONDRAWERQT_H
