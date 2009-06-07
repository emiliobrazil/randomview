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
    void drawPath( QPainter &painter );
    void drawPath( QPainter &painter , Path& path );

private:
    void paintEvent( QPaintEvent *event );

    std::vector<Path> allPath;
};

#endif // PATHVIEWER_H
