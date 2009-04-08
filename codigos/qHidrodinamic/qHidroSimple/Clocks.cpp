#include "Clocks.hpp"

#include <math.h>

#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>


#include "random_functions.h"

std::pair<uint32,real> minimun( const std::vector<real>& clock );

Clocks::Clocks(  uint32 N , real t , real alpha )
{
	setSeed(  time(NULL) );

	this->_actualTime = 0 ;

	real tmp = pow( (real)N , alpha ) * t;

	this->_numberOfEvents = (uint32)tmp ;

	this->_N = N;
}

Clocks::~Clocks( void )
{

}

bool Clocks::isEmpty( void )
{
	return ( (this->_actualTime) >= ( this->_numberOfEvents) ) ;
}

uint32 Clocks::findNext( void )
{
        this->_actualTime += exponential( 1.0 );
	return (uint32)( rand() % this->_N );
}

std::pair<uint32,real> minimun( const std::vector<real>& clock )
{
	uint32 numberOfsites = clock.size();

	uint32 index = 0;
	real min = clock[0];

	for(uint32 i = 1; i < numberOfsites ; ++i )
	{
		if( clock[i] < min )
		{
			min = clock[i];
			index = i;
		}
	}
	return std::pair< uint32,real > (index , min);
}


