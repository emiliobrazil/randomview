#ifndef PERCOLATIONDRAWERQT_H
#define PERCOLATIONDRAWERQT_H

#include <QWidget>
#include <QPainter>

#include "path.hpp"
#include "edge.hpp"

class PercolationDrawerQT
{
public:
    PercolationDrawerQT();

    void pathDrawer( QPainter &painter , int windowWidh ,  int windowHeight ,
                                    int systemStartX , int systemStartY ,
                                    int systemEndX ,  int systemEndY );

};

#endif // PERCOLATIONDRAWERQT_H
