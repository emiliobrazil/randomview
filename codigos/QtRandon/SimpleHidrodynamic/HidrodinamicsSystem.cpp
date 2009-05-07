
#include "HidrodinamicsSystem.hpp"

HidrodinamicsSystem::HidrodinamicsSystem( uint32 N , real t , real alpha , FDP function )
{
	this->_particles =  HidrodinamicsParticles(  N , function );
	this->_clocks = Clocks( N , t , alpha );
}

ParticlesCounter HidrodinamicsSystem::process( void )
{
	while( !this->_clocks.isEmpty() )
	{
		uint32 i = this->_clocks.findNext() ;
		this->_particles.visit( i ) ;
	}
	return this->_particles.counter();
}
