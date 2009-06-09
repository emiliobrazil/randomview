#include "types.hpp"

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle
{
private:
    ORIENTATION pOri;
    Site pActualPosition;
public:
    Particle();
    Particle( Site startPosition );
    Site goNextPosition( const PercolationProcess& percolation );
    bool isOutBox( void );
    Site position( void );
};

#endif
