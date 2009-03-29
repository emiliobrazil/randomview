
#include <math.h>
#include <stdlib.h>

#include "random_functions.h"

#include "primitive_const.h"

void setSeed( unsigned int seed )
{
	srand( seed ) ;
}

real uniform01( void )
{
	return (real)rand()/(real)RAND_MAX;
}

uint32 uniform1max( uint32 max )
{
	return (rand() % max) + 1 ;
}

real uniformAB( real A , real B )
{
	real r = uniform01() ;
	return A + r * ( B - A ) ;
}

uint32 bernoulli( real p )
{
	real r = uniform01( );
	uint32 b = 0 ;
	if ( r <= p ) b = 1 ; 
	return  b ;
}

real exponential( real lambda )
{
	return -log( uniform01() )/lambda;
}
