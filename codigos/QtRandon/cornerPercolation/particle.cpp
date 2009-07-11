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

bool Particle::walk( PercolationProcess& percolation )
{
    Site next( startPosition );
    bool in_box_c = percolation.inBox( next );
    bool in_box_p = percolation.inBox( next );

    // Corner Path
    ORIENTATION o;
    int x, y;

    x = startPosition.X();
    y = startPosition.Y();

    o = ( abs(x) + abs(y) ) % 2 == 0  ? H : V;

    corner_path.add( startPosition );

    while ( !corner_path.isClosed() && in_box_c ) {

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

        x = next.X();
        y = next.Y();

        o = ( abs(x) + abs(y) ) % 2 == 0  ? H : V;
        in_box_c = percolation.inBox( next );
    }

    next = startPosition;
    in_box_p = percolation.visit( next );

    x = startPosition.X();
    y = startPosition.Y();

    o = ( abs(x) + abs(y) ) % 2 == 0  ? H : V;

    perturbed_path.add( next );

    int stepX = 0, stepY = 0;

    switch( o ) {
    case H:
        stepX = percolation.primalY( next.Y() ) == true ? 1 : -1;
        stepY = 0;
        break;
    case V:
        stepY = percolation.primalX( next.X() ) == true ? 1 : -1;
        stepX = 0;
        break;

    default: break;
    }

    while ( !perturbed_path.isClosed() && in_box_p ) {

        if ( !percolation.isOpen( next ) ) {
            x = next.X();
            y = next.Y();

            o = ( abs(x) + abs(y) ) % 2 == 0  ? H : V;

            switch( o ) {
            case H:
                stepX = percolation.primalY( next.Y() ) == true ? 1 : -1;
                stepY = 0;
                break;
            case V:
                stepY = percolation.primalX( next.X() ) == true ? 1 : -1;
                stepX = 0;
                break;

            default: break;
            }

            next.add( stepX, stepY );
        }
        else {
            next.add( stepX, stepY );
        }

        in_box_p = percolation.visit( next );
        perturbed_path.add( next );
    }    
}

std::vector<Path>& Particle::getPaths( void ) {

    std::vector<Path> paths;

    paths.push_back(corner_path);
    paths.push_back(perturbed_path);

    return paths;
}

Path& Particle::getCorner( void ) {

    return corner_path;
}

Path& Particle::getPerturbed( void ) {

    return perturbed_path;
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
