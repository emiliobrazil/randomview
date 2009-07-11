#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include "types.hpp"
#include "path.hpp"
#include "percolation_process.hpp"

class Particle
{
public:
    Particle();
    Particle( Site startPositionNew );
    Particle( const Particle &p );
    Particle& operator=( const Particle &p );

    bool walk( PercolationProcess& percolation );
    bool isOutBox( void ){ return false;}
    std::vector<Path>& getPaths( void );

    Path& getCorner( void );
    Path& getPerturbed( void );




private:
//    ORIENTATION pOri;
    Site startPosition;
//    std::vector<Path> paths;

    Path corner_path;
    Path perturbed_path;
};

#endif
