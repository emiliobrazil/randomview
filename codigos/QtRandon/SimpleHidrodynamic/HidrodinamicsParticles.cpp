
#include "HidrodinamicsParticles.hpp"

HidrodinamicsParticles::HidrodinamicsParticles( uint32 N , FDP function )
{
	this->_particles = std::vector<bool>( N , false );
	real delta = 1.0f / (real)N ;
	real max = function.max() ;

	for( uint32 i = 0 ; i < N ; ++i )
	{
                if( function.eval( i*delta ) >= ( max * uniform01() ) ) this->_particles[i] = true;
	}
}

HidrodinamicsParticles::~HidrodinamicsParticles( void )
{

}

void HidrodinamicsParticles::visit( uint32 site )
{
	uint32 N = this->_particles.size();
	if( this->_particles[site] )
	{
		uint32 p = bernoulli( 0.5 );
		if( p )
		{
			uint32 NS = ( site + 1 ) % N;
			this->_particles[ site ] = this->_particles[ NS ];
			this->_particles[ NS ] = true;
		}
		else
		{
			uint32 PS = ( (int)site - 1 ) % N;
			this->_particles[ site ] = this->_particles[ PS ];
			this->_particles[ PS ] = true;
		}
	}
}

ParticlesCounter HidrodinamicsParticles::counter(void)
{
	uint32 N = this->_particles.size();
	ParticlesCounter counter( N );
	for( uint32 i = 0 ; i < N ; ++i )
	{
		if( this->_particles[i] ) counter.set( i , 1.0f );
	}

	return counter;
}
