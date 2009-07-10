#include "particle.hpp"

Site Particle::walk( const PercolationProcess& percolation )
{
    Site head = startPosition;

    Path path;

    for( int i = 0 ; i < 100 ; ++i)
    {
       ( head.X()%2 == 0 || !percolation.isVisited(head) ) ? head.addX(1) :  head.addX(-1) ;
       ( head.Y()%2 == 1 )                                 ? head.addY(1) :  head.addY(-1) ;
       path.add( head );
    }
    paths.push_back( path);
}
