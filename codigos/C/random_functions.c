
#include <math.h>
#include <stdlib.h>

#include "random_functions.h"

#include "primitive_const.h"

void setSeed( unsigned int seed )
{
  srand( seed ) ;
}

real unifor01( void )
{
  return (real)rand()/(real)RAND_MAX;
}

uint32 unifor1max( uint32 max )
{
  return (rand() % max) + 1 ;
}

real uniforAB( real A , real B )
{
  real r = unifor01() ;
  return A + r * ( B - A ) ;
}

uint32 bernoulli( real p )
{
  real r = unifor01( );
  uint32 b = 0 ;
  if ( r <= p ) b = 1 ; 
  return  b ;
}

real exponential( real lambda )
{
  return -log( unifor01() )/lambda;
}
