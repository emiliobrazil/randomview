#include "particle.hpp"
#include <iostream>

Particle::Particle()
{
    Particle p( Site(0, 0) );
    (*this) = p;
}

Particle::Particle( Site s )
{
    startPosition = s;
}

Particle::Particle( const Particle &p ) {
    (*this) = p;
}

Particle& Particle::operator=( const Particle &p ) {

    this -> startPosition = p.startPosition;

    //std::vector<Path> tmp = p.getPaths();

    this -> perturbed_path = p.perturbed_path;
    this -> corner_path = p.corner_path;

    return (*this);
}

bool Particle::walk( const PercolationProcess& percolation )
{
    Site next( startPosition );
    bool in_box = true;

    // Corner Path
    ORIENTATION o;
    o = (startPosition.X() + startPosition.Y()) % 2 == 0  ? H : V;

    corner_path.add( startPosition );

    while ( !corner_path.isClosed() && percolation.inBox( next ) ) {

        int step = 0;

        switch( o ) {
        case H:
            step = percolation.primalY( next.Y() ) == true ? 1 : -1;
            next.addX( step );
            break;
        case V:
            step = percolation.primalX( next.X() ) == true ? 1 : -1;
            next.addY( step );
            break;

        default: break;
        }

        corner_path.add( next );
    }

    perturbed_path.add( startPosition );
}

std::vector<Path>& Particle::getPaths( void ) const {

    std::vector<Path> paths;

    paths.push_back(corner_path);
    paths.push_back(perturbed_path);

    return paths;
}

    // Perturbed Path

//    Site head = startPosition;
//    std::cout << "Site Particle::walk( const PercolationProcess& percolation )  " << head.X() << "   " << head.Y() << std::endl;
//
//    Path path( head );
//
//
//    for( int i = 0 ; i < 100 ; ++i)
//    {
//       head.add( 1,0);
//       path.add( head );
//       head.add( 0,1);
//       path.add( head );
//    }
//    paths.push_back( path);
//    return head;
