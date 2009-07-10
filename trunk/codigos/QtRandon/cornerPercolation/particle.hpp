#include "types.hpp"

#ifndef PARTICLE_HPP
#define PARTICLE_HPP

class Particle
{
private:
    ORIENTATION pOri;
    Site pActualPosition;
public:
    Particle(){ }
    Particle( Site startPosition ){ pActualPosition = startPosition;}
    Site goNextPosition( const PercolationProcess& percolation ){ if(position.X()%2 == 0 ) pActualPosition.addX(1) ; if(position.X()%2 == 1 )pActualPosition.addY(0); return pActualPosition; }
    bool isOutBox( void ){ return false;}
    Site position( void ){ return pActualPosition; }
};

#endif
