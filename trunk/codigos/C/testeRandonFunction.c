#include "random_functions.h"
#include "primitive_types.h"
#include <stdio.h>



int main( void )
{
	uint32 i;
	for( i = 0 ;  i < 5 ; ++i )
	{
		fprintf( stdout, "%d) uniform [0,1] = %f\n" , i+1 , unifor01() );
		fprintf( stdout, "   uniform [-2.3 , -1.8 ] = %f\n" , uniforAB(-2.3 , -1.8) );
		fprintf( stdout, "   uniform 1 - 5 = %d\n" , unifor1max( 5 ) );
		fprintf( stdout, "   bernoulli (1/3) = %d\n" , bernoulli(1.0/3.0) );
		fprintf( stdout, "   exponential (1.2) = %f\n" , exponential(1.2) );
	}

	uint32 seed = 100;
		fprintf( stdout, "========================>>> new seed = %d\n" , seed );

	setSeed( seed );

	for( i = 0 ;  i < 5 ; ++i )
	{
		fprintf( stdout, "%d) uniform [0,1] = %f\n" , i+1 , unifor01() );

	}

		fprintf( stdout, "========================>>> new seed = %d\n" , seed );

	setSeed( seed );

	for( i = 0 ;  i < 5 ; ++i )
	{
		fprintf( stdout, "%d) uniform [0,1] = %f\n" , i+1 , unifor01() );
	}

	seed = 0;
		fprintf( stdout, "========================>>> new seed = %d\n" , seed );

	setSeed( seed );

	for( i = 0 ;  i < 5 ; ++i )
	{
		fprintf( stdout, "%d) uniform [0,1] = %f\n" , i+1 , unifor01() );
	}
	return 0;
}

