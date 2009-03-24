#ifndef _CLOCKS_HPP_
#define _CLOCKS_HPP_

#include <vector>

#include "random_functions.h"
#include "primitive_types.h"


class Clocks
{
public:
	Clocks(  uint32 N , real t , real alpha );
	~Clocks( void );

	bool isEmpty( void );

	uint32 findNext( void );
private:
	std::vector<uint32> _indexOrder;
	uint32 _actualTime;
}

std::pair<uint32,real> minimun( const std::vector<real>& clock );

#endif //_CLOCKS_HPP_