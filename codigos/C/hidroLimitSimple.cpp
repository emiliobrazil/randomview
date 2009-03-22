
#include "random_functions.h"

MAIN
// D number of process loop
for( uint32 i = 0 ; i < D ; ++i )
{

	// N            -> number of sites;
	// t, alpha     -> parameters to limite time (N^alpha)*t; 
	// FDP function -> define the initial possicion of the particles
	sistem.initialize( uint32 N , real t , real alpha , FDP function )

	//counter count the number of particles in the site J after each process 
	counter += sistem.process();
}
return  counter/D

sistem::initialize( uint32 N , real t , real alpha , FDP function )
{
	particles.initialize( uint32 N , FDP function )
	clocks.initialize(  uint32 N , real t , real alpha , )
}

sistem::process()
{
	while( !clocks.isEmpty() )
	{
		uint32 i = clocks.findNext()
		particles.visit(i)
	}
	return counter;
}

particles::initialize( uint32 N , FDP function )
{
	std::vector<bool> particles( N , false )
	real delta = 1.0f/(real)N
	for( uint32 i = 0 ; i < N ; ++i )
	{
		if( function.eval( i*delta ) < ( function.max() * uniform01() ) ) particles[i] = true
	}
}

particles::visit( uint32 site )
{
	if( particles[site] )
	{
		uint32 p = bernoulli( 0.5 )
		if( p )
		{
			uint32 NS = ( site + 1 ) % N
			particles[ site ] = particles[ NS ]
			particles[ NS ] = true
		}
		else
		{
			uint32 PS = ( (int)site - 1 ) % N
			particles[ site ] = particles[ PS ]
			particles[ PS ] = true
		}
	}
}

clocks::initialize(  uint32 N , real t , real alpha )
{
	for(uint32 i = 0 , i < N , ++i )
	{
		real timeLimite = (N^alpha)*t
		bool thereIsParticleInTime = true
		std::vector<real> clock( N , 0.0f )
		std::vector<uint32> indexOrder;
		for( uint32 j = 0 ; j < N ; ++j) clock[j]= exponential( 1.0 )
		while( thereIsParticleInTime )
		{
			std::pair<index,real> minTest
			minTest = minimun( clock )
			if( minTest.second < timeLimite )
			{
				indexOrder.push_back( minTest.first )
				clock[minTest.first]+=exponential(1.0)
			}
			else thereIsParticleInTime = false
		}
	}
}

clocks::findNext( void )
{
	++clocks::counter
	return indexOrder[ couter-1 ]
}

std::pair<uint32,real> minimun( const std::vector<real>& clock )
{
	uint32 = numberOfsites = clock.size();

	uint32 index = 0;
	real min = clock[0]

	for(uint32 i = 1; i < numberOfsites ; ++i )
	{
		if( clock[i] < min )
		{
			min = clock[i]
			index = i
		}
	}
	return std::pair< uint32,real > (index , min)
}
