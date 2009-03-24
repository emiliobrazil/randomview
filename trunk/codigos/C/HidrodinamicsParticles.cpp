#include "HidrodinamicsParticles.hpp"

HidrodinamicsParticles::HidrodinamicsParticles( uint32 N , FDP function )
{
	this->_particles = std::vector<bool>( N , false );
	real delta = 1.0f / (real)N ;
	real max = function.max() ;

	for( uint32 i = 0 ; i < N ; ++i )
	{
		if( function.eval( i*delta ) < ( max * uniform01() ) ) particles[i] = true;
	}
}

HidrodinamicsParticles::~HidrodinamicsParticles( void )
{

}

HidrodinamicsParticles::visit( uint32 site )
{
	if( this->_particles[site] )
	{
		uint32 p = bernoulli( 0.5 );
		if( p )
		{
			uint32 NS = ( site + 1 ) % N;
			particles[ site ] = particles[ NS ];
			particles[ NS ] = true;
		}
		else
		{
			uint32 PS = ( (int)site - 1 ) % N;
			particles[ site ] = particles[ PS ];
			particles[ PS ] = true
		}
	}
}
