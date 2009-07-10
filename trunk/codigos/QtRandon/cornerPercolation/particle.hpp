#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "types.hpp"
#include "path.hpp"
#include "percolation_process.hpp"

class Particle
{
public:
    Particle(){ }
    Particle( Site startPositionNew ){ startPosition = startPositionNew; }
    // TODO Copy builder
    Site walk( const PercolationProcess& percolation );
    bool isOutBox( void ){ return false;}
    std::vector<Path>& getPaths( void ){ return paths; }


private:
    ORIENTATION pOri;
    Site startPosition;
    std::vector<Path> paths;
};

#endif
