#include "types.hpp" 
#include "site.hpp" 
#include "edge.hpp" 
#include <vector>

#include <cstdlib>
#include <cassert>

#ifndef PERCOLATION_PROCESS_HPP
#define PERCOLATION_PROCESS_HPP

#include <lua5.1/lua.hpp>
extern lua_State *L;

class PercolationProcess
{
private:
    PERCOLATION pType;
    std::vector<bool> pPrimalX;
    std::vector<bool> pPrimalY;
    std::vector<bool> pDualX;
    std::vector<bool> pDualY;
    unsigned int pRadiusX , pRadiusY;
    std::vector<bool> pVisitedSites;
    std::vector<bool>  pKeysOfSitesVisited;

public:
    PercolationProcess();
    PercolationProcess( unsigned int radiusX, unsigned int radiusY );
    PercolationProcess( const PercolationProcess& );

    PercolationProcess& operator=( const PercolationProcess& );

    bool isOpen( const Edge& e) const {
        lua_getglobal(L,"isOpen");
        lua_pushnumber( L , e.position().X() );
        lua_pushnumber( L , e.position().Y() );
        lua_call( L , 2 , 1 );
        bool r =lua_toboolean(L,-1);
        lua_pop(L,1);
        return r;
    }
    bool isOpen( const Site& ) const;//  { return((double)rand()/(double)RAND_MAX) < 0.4;} // key
    bool isVisited( Site ) const;
    bool dualX( int i ) const;
    bool dualY( int j ) const;
    bool primalX( int i  ) const;
    bool primalY( int j ) const;

    bool visit( const Site & );

    // Helper functions: as long as the box is fixed
private:
    unsigned int getIndex( const Site& s ) const;
    unsigned int getX( int i ) const;
    unsigned int getY( int j ) const;
    bool inBox( const Site & ) const;
};


#endif
