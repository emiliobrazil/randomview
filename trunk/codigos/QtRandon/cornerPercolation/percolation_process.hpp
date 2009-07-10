#include "types.hpp" 
#include "site.hpp" 
#include "edge.hpp" 
#include <vector>

#include <cstdlib>
#include <cassert>

#ifndef PERCOLATION_PROCESS_HPP
#define PERCOLATION_PROCESS_HPP

class PercolationProcess
{
public:
    PercolationProcess();
    PercolationProcess( unsigned int radiusX, unsigned int radiusY, double probS );
    PercolationProcess( const PercolationProcess& );

    PercolationProcess& operator=( const PercolationProcess& );

    bool isOpen( const Edge& ) const;
    bool isOpen( const Site& ) const;
    bool isVisited( Site ) const;
    bool dualX( int i ) const;
    bool dualY( int j ) const;
    bool primalX( int i  ) const;
    bool primalY( int j ) const;

    bool visit( const Site & );

private:
    PERCOLATION pType;
    std::vector<bool> pPrimalX;
    std::vector<bool> pPrimalY;
    std::vector<bool> pDualX;
    std::vector<bool> pDualY;
    unsigned int pRadiusX , pRadiusY;
    std::vector<bool> pVisitedSites;
    std::vector<bool>  pKeysOfSitesVisited;

    double pProbS;


    // Helper functions: as long as the box is fixed
private:
    unsigned int getIndex( const Site& s ) const;
    unsigned int getX( int i ) const;
    unsigned int getY( int j ) const;
    bool inBox( const Site & ) const;

};


#endif
