#include "types.hpp"

#ifndef SITE_HPP
#define SITE_HPP

class Site
{
private:
    int position[2];

public:
    Site();
    Site(  int x,  int y );
    Site( const Site & s );

    Site& operator=( const Site& s );
    bool operator==( const Site& s );
    int X( void ) const;
    int Y( void ) const;
    void setX( int x );
    void setY( int y );
    void add( int stepX , int stepY );
    void addX( int step );
    void addY( int step );
};

#endif
