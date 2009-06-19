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

//        real eval( real x ) { return -4.0 * (x-0.5) * (x-0.5) + 1.0 ; }
//      real eval( real x ) { return 1.0*x ; }
//      real eval( real x ) { return (x<.5) ? 2.0*x : 2.0 - 2.0*x ; }
        real eval( real x ) { return (x<.2) ? 5.0*x : (5.0 - 5.0*x)*.25 ; }
//        real eval( real x ) { if (x<.1)  return 1.0;
//                               else if (x<.25) return x*4.0;
//                               else if (x<.5 ) return .8;
//                               else if (x<.75) return .1;
//                               else if (x<.95) return .5;
//                               else return 1.0;
//                           }


        real max( void ) {return 1.0 ; }
};

#endif //_FDP_HPP_  −4∙(x−.5)²+1
