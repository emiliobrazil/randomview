#ifndef _FDP_HPP_
#define _FDP_HPP_

#include <vector>

#include<math.h>

#include "random_functions.h"
#include "primitive_types.h"
#include "primitive_const.h"

class FDP
{
public:
    FDP( void ){ func = QUADRATIC;}
    FDP( FDP_FUNC func ){ this->func = func; }
    ~FDP( void ){}

    real eval( real x)
    {
        real v;
        switch ( func )
        {
        case QUADRATIC:
            v = quadratic( x );
            break;
        case LINEAR:
            v = linear( x );
            break;
        case PIECEWISE_LINEAR_01:
            v = pwLinear01( x );
            break;
        case PIECEWISE_LINEAR_02:
            v = pwLinear02( x );
            break;
        case NON_CONTINUOS:
            v = nonContinuos( x );
            break;
        case GAUSIAN:
            v = gausian( x );
            break;
        default:
            v = 0.5;
            break;
                }
        return v;
    }

    real max( void ) {return 1.0 ; }

private:
        real quadratic( real x ) { return -4.0 * (x-0.5) * (x-0.5) + 1.0 ; }
        real linear( real x ) { return 1.0*x ; }
        real pwLinear01( real x ) { return (x<.5) ? 2.0*x : 2.0 - 2.0*x ; }
        real pwLinear02( real x ) { return (x<.2) ? 5.0*x : (5.0 - 5.0*x)*.25 ; }
        real nonContinuos( real x ) { if (x<.1)  return 1.0;
                            else if (x<.25) return x*4.0;
                            else if (x<.5 ) return .8;
                            else if (x<.75) return .1;
                            else if (x<.95) return .5;
                            else return 1.0;
        }

        real gausian(real x){ return exp(-4.0*PI*(x-.5)*(x-.5));}


        FDP_FUNC func;

};

#endif //_FDP_HPP_
