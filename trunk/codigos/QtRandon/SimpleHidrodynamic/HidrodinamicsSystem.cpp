
#include "HidrodinamicsSystem.hpp"

HidrodinamicsSystem::HidrodinamicsSystem( uint32 N , real t , real alpha , FDP function )
{
	this->_particles =  HidrodinamicsParticles(  N , function );
	this->_clocks = Clocks( N , t , alpha );
}

HidrodinamicsSystem::HidrodinamicsSystem( uint32 N , real t , real alpha , FDP function , real beta )
{
        this->_particles =  HidrodinamicsParticles(  N , function  , beta );
        this->_clocks = Clocks( N , t , alpha , beta );
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
