#include "types.hpp"
#include "site.hpp"
#include "edge.hpp"
#include<vector>

#ifndef _PATH_HPP
#define _PATH_HPP

class Path
{

public:
    Path( void );
    Path( const Site& startPosition );
    Path( const Path& );

    Path& operator=( const Path& p );

    unsigned int size( void );
    bool isInPath( const Site& s );
    void add( const Site& s );
    bool isClosed( void ) const;
    const Site& getSite( int index ) const; 

private:
    std::vector<Site> pPath;
    std::vector<Site>::iterator iterator;
    bool pIsClosed;
};

#endif
