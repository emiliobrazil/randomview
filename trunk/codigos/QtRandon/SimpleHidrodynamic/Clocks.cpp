#include "Clocks.hpp"

#include <math.h>

#include <iostream>
#include <time.h>


std::pair<uint32,real> minimun( const std::vector<real>& clock );

Clocks::Clocks(  uint32 N , real t , real alpha )
{
	time_t start,end;
	time (&start);
	std::cerr << "Setting Clocks ... " << std::endl;

	setSeed(  time(NULL) );

	this->_actualTime = 0 ;
	for(uint32 i = 0 ; i < N ; ++i )
	{
		real timeLimite =  pow(N,alpha) * t ;
		bool thereIsParticleInTime = true ;
		this-> _indexOrder = std::vector<uint32>() ;

		std::vector<real> clock( N , 0.0f );
		for( uint32 j = 0 ; j < N ; ++j )
		{
			clock[j] = exponential( 1.0 ) ;
		}

		while( thereIsParticleInTime )
		{
			std::pair<uint32,real> minTest;
			minTest = minimun( clock );
			if( minTest.second < timeLimite )
			{
				this->_indexOrder.push_back( minTest.first );
				clock[minTest.first]+=exponential(1.0);
			}
			else thereIsParticleInTime = false;
		}
	}

	double dif;
 	time (&end);
	dif = difftime (end,start);

	std::cerr << "Clocks Seted in " << dif << " Seconds; number of cloks = " << this->_indexOrder.size() << std::endl;
}

Clocks::~Clocks( void )
{

}

bool Clocks::isEmpty( void )
{
	return ( (this->_actualTime) >= ( this->_indexOrder.size() ) ) ;
}

uint32 Clocks::findNext( void )
{
	++(this->_actualTime);
	return this->_indexOrder[ _actualTime - 1 ];
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


