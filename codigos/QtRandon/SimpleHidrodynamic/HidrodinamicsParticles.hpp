#ifndef _HIDRODINAMICSPARTICLES_HPP_
#define _HIDRODINAMICSPARTICLES_HPP_

#include <vector>

#include "random_functions.h"
#include "primitive_types.h"

#include "FDP.hpp"
#include "ParticlesCounter.hpp"

class HidrodinamicsParticles
{
public:
    enum dynamicType { ALPHA , ALPHABETA };

    HidrodinamicsParticles( void ){}
    HidrodinamicsParticles( uint32 N , FDP function );
    HidrodinamicsParticles( uint32 N , FDP function ,  real beta );
    ~HidrodinamicsParticles( void );

    void visit( uint32 site );
    ParticlesCounter counter( void );

protected:
    void normalVisit( uint32 site );
    void badVisit(uint32 site);

private:
    std::vector<bool> _particles;
    dynamicType _type;
    real _beta;
    real _betaN;
    uint32 _badSite;

};

#endif // _HIDRODINAMICSPARTICLES_HPP_

