#ifndef _FDP_HPP_
#define _FDP_HPP_

#include <vector>

#include "random_functions.h"
#include "primitive_types.h"

class FDP
{
public:
	FDP( void ){}
	~FDP( void ){}

	real eval( real x ) { return -4.0 * (x-0.5) * (x-0.5) + 1.0 ; }
	real max( void ) {return 1.0 ; }
};

#endif //_FDP_HPP_  −4∙(x−.5)²+1
