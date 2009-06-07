#include "types.hpp"
#include "site.hpp"

#ifndef _EDGE_HPP
#define _EDGE_HPP

class Edge
{
private:
    Site base;
    ORIENTATION head;

public:
    Edge();
    Edge( Site position , ORIENTATION ori );
    Edge( const Edge& );

    Edge& operator=( const Edge& );

    ORIENTATION orientation( void );
    Site position( void );
};

#endif
