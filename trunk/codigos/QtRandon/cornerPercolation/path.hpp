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

    unsigned int size( void ) const;
    bool isInPath( const Site& s );
    void add( const Site& s );
    bool isClosed( void );
    const Site& getSite( int index ) const; 

    // helper functions -- exists only because Path is a vector of Site
private:
    ORIENTATION getHead( const Site&, const Site& ) const;

private:
    std::vector<Site> pPath;
    //    std::vector<Site>::iterator iterator;

    // Lexicographic order in Edges ( < )
    struct less {
        bool operator()( const Edge& e1, const Edge& e2 ) const {
            int dx = 0, dy = 0;
            bool dO;

            dx = e1.position().X() - e2.position().X();
            dy = e1.position().Y() - e2.position().Y();
            dO = e1.orientation() == H && e2.orientation() == V;

            if ( dx < 0 ) { return true; }
            else if ( dx == 0 && dy < 0 ) { return true; }
            else if ( dy == 0 && dO ) { return true; }

            return false;
        }
    };
    std::set<Edge, less> tail_path;
    Site head_site;

    bool pIsClosed;
};

#endif
