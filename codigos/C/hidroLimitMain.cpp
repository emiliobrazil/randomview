
#include "HidrodinamicsSystem.hpp"

#include <iostream>

int main( void )
{
	uint32 D = 100, N = 50;
	real t = 0.5f , alpha = 1.0f ;
	FDP function;
	
std::cerr << "initialize counter " << std::endl;
	ParticlesCounter counter( N );
std::cerr << "end counter " << std::endl;

	for( uint32 i = 0 ; i < D ; ++i )
	{
std::cerr << "initialize system " << i << std::endl;
		HidrodinamicsSystem system(  N ,  t ,  alpha ,  function );
std::cerr << "system Ok " << i << std::endl;
		counter += system.process();
std::cerr << "end process " << i << std::endl;
	}
	counter*(1/(real)D);
	return 0;
}

