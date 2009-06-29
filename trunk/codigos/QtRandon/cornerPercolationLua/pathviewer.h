#ifndef PATHVIEWER_H
#define PATHVIEWER_H

#include <QWidget>

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

    QSize frameSize;

    std::vector<Path> allPath;
};

#endif // PATHVIEWER_H
