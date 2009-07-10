#include "site.hpp"

#include <stdio.h>

Site::Site( void ) {
    this -> position[0] = 0;
    this -> position[1] = 0;
} 

Site::Site(  int x ,  int y ) {
    this -> position[0] = x;
    this -> position[1] = y;
} 

Site::Site( const Site &site ) {
    (*this) = site;
}

Site& Site::operator=( const Site &s ) {
    this -> position[0] = s.X();
    this -> position[1] = s.Y(); 

    return (*this);
} 

bool Site::operator==( const Site &s ) { 
    int equalX, equalY;

    equalX = this -> X() - s.X();
    equalY = this -> Y() - s.Y();

    return (equalX && equalY);
} 

int Site::X( void ) const { return this -> position[0]; } 

int Site::Y( void ) const { return this -> position[1]; } 

void Site::setX( int x ) { this -> position[0] = x; }

void Site::setY( int y ) { this -> position[1] = y; } 

void Site::addX( int step ) { this -> position[0] += step;/* fprintf( stderr, "Site::addX %d\n" , position[0] );*/ }

void Site::addY( int step ) { this -> position[1] += step;/* fprintf( stderr, "Site::addY %d\n" , position[1] );*/ }

