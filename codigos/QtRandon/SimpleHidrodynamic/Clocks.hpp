#ifndef _CLOCKS_HPP_
#define _CLOCKS_HPP_

#include "primitive_types.h"
#include "random_functions.h"


class Clocks
{
public:

        Clocks( void ){ }
        Clocks(  uint32 N , real t , real alpha );
        Clocks(  uint32 N , real t , real alpha , real beta);

        ~Clocks( void );

        bool isEmpty( void );

        uint32 findNext( void );


private:
        uint32 _actualTime;
        uint32 _numberOfEvents;
        uint32 _N;
};

#endif //_CLOCKS_HPP_
