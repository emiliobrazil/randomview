
#include "random_functions"

#include <math.h>
#include "primitives_const.h"

real unifor01( uint32 seed )
{
  return rand()/RAND_MAX;
}

uint32 unifor1max( uint32 max );
{
  return rand % max + 1 ;
}

real uniforAB( real A , real B )
{
  real r = unifor01() ;
  return A + r * ( B - A ) ; 
}

uint32 bernoulli( real p )
{
  real r = unifor01( );
  return ( r <= p ) ? 1 : 0 ;    
}

real exponential( real lambda )
{
  return -log( unifor01() )/lambda;
}
