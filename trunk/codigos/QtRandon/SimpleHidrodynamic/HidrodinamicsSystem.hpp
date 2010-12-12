#ifndef _HIDRODINAMICSYSTEM_HPP_
#define _HIDRODINAMICSYSTEM_HPP_


#include "primitive_types.h"

#include "HidrodinamicsParticles.hpp"
#include "Clocks.hpp"
#include "ParticlesCounter.hpp"

class HidrodinamicsSystem 
{
public:
	HidrodinamicsSystem( uint32 N , real t , real alpha , FDP function );

        HidrodinamicsSystem( uint32 N , real t , real alpha , FDP function , real beta );


	ParticlesCounter process( void );
  
private:
	Clocks _clocks;
	HidrodinamicsParticles _particles;

};

#endif // _HIDRODINAMICSYSTEM_HPP_
