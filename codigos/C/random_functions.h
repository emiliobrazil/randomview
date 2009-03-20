#ifndef _RANDOM_FUNCTIONS_H_
#define _RANDOM_FUNCTIONS_H_

#include "primitives_types.h"

inline void setSeed( uint32 seed ){ srand( seed ) ; }
real unifor01( void );
real uniforAB( real A , real B );
uint32 unifor1max( uint32 max );
real bernoulli( real p );
real exponential( real lambda );

#endif // _RANDOM_FUNCTIONS_H_