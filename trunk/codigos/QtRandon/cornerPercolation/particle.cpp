#include "particle.hpp"
#include <iostream>

Site Particle::walk( const PercolationProcess& percolation )
{
    Site head = startPosition;
    std::cout << "Site Particle::walk( const PercolationProcess& percolation )  " << head.X() << "   " << head.Y() << std::endl;

    Path path( head );


    for( int i = 0 ; i < 100 ; ++i)
    {
       head.add( 1,0);
       path.add( head );
       head.add( 0,1);
       path.add( head );
    }
    paths.push_back( path);
    return head;
}
