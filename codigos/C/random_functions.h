#ifndef _RANDOM_FUNCTIONS_H_
#define _RANDOM_FUNCTIONS_H_

#include "primitive_types.h"

void setSeed( unsigned int seed );
real unifor01( void );
real uniforAB( real A , real B );
uint32 unifor1max( uint32 max );
uint32 bernoulli( real p );
real exponential( real lambda );

#endif // _RANDOM_FUNCTIONS_H_
