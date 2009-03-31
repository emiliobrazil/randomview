
#include "HidrodinamicsSystem.hpp"

#include <iostream>

int main( void )
{
	uint32 D = 100, N = 100;
	real t = 0.1f , alpha = 1.0f ;
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
	ParticlesCounter tmp = counter*( 1.0/real( i+1 ) ) ;

	tmp.print();

	}
	(counter*=(1/(real)D));
	counter.print();
	return 0;
}

