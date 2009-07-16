#include "types.hpp" 
#include "site.hpp" 
#include "edge.hpp" 
#include "random_functions.h"
#include <vector>

#include <cstdlib>
#include <cassert>

#ifndef PERCOLATION_PROCESS_HPP
#define PERCOLATION_PROCESS_HPP

class PercolationProcess
{
public:
    ~PercolationProcess();
    PercolationProcess( unsigned int radiusX = 150, unsigned int radiusY = 150, double probS = 0.002 );
    PercolationProcess( const PercolationProcess& );

    const PercolationProcess& operator=( const PercolationProcess & );

    bool isOpen( const Edge& ) const;
    bool isOpen( Site& ) const;
    bool isVisited( Site ) const;
    bool dualX( int i ) const;
    bool dualY( int j ) const;
    bool primalX( int i  ) const;
    bool primalY( int j ) const;

    bool visit( Site & ) ;

    bool inBox( Site & ) const;

    unsigned int radiusX( void );
    unsigned int radiusY( void );

private:
    PERCOLATION pType;
    bool *pPrimalX;
    bool *pPrimalY;
    bool *pDualX;
    bool *pDualY;
    unsigned int pRadiusX , pRadiusY;
    bool *pVisitedSites;
    bool *pKeysOfSitesVisited;

    double pProbS;

    // Helper functions: as long as the box is fixed
private:
    unsigned int getIndex( const Site& s ) const;
    unsigned int getX( int i ) const;
    unsigned int getY( int j ) const;
};


#endif
