#include "types.hpp"
#include "site.hpp"

#ifndef EDGE_HPP
#define EDGE_HPP

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

    const ORIENTATION orientation( void ) const;
    const Site& position( void ) const;
};

#endif
