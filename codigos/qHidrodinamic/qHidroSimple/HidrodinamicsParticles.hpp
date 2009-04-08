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
	HidrodinamicsParticles( void ){}
	HidrodinamicsParticles( uint32 N , FDP function );
	~HidrodinamicsParticles( void );

	void visit( uint32 site );
	ParticlesCounter counter( void );

private:
	std::vector<bool> _particles;
};

#endif // _HIDRODINAMICSPARTICLES_HPP_

