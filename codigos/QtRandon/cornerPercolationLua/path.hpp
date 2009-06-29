#include "types.hpp"
#include "site.hpp"
#include "edge.hpp"
#include <cassert>
#include <vector>
#include <set>
#include <utility>

#ifndef PATH_HPP
#define PATH_HPP

class Path
{

public:
    Path( void );
    Path( const Site& startPosition );

    // Path is more intuitive if we think about edges
    Path( const Edge& startPosition );

    Path( const Path& );

    Path& operator=( const Path& p );

    unsigned int size( void );
    bool isInPath( const Site& s );
    void add( const Site& s );
    bool isClosed( void ) const;
    const Site& getSite( int index ) const; 

    // helper functions -- exists only because Path is a vector of Site
private:
    ORIENTATION getHead( const Site&, const Site& ) const;

private:
    std::vector<Site> pPath;
//    std::vector<Site>::iterator iterator;
    bool pIsClosed;
};

#endif
