#include "types.hpp" 
#include "site.hpp" 
#include "edge.hpp" 
#include <vector>

#include <stdlib.h>

#ifndef PERCOLATION_PROCESS_HPP
#define PERCOLATION_PROCESS_HPP

class PercolationProcess
{
private:
    PERCOLATION pType;
    std::vector<bool> pPrimalX;
    std::vector<bool> pPrimalY;
    std::vector<bool> pDualX;
    std::vector<bool> pDualY;
    unsigned int pRadiusX , pRadiusY;
    std::vector<Site> pVisitedSites;
    std::vector<bool>  pKeysOfSitesVisited;

public:
    PercolationProcess(){}
    PercolationProcess( unsigned int radiusX , unsigned int radiusY );
    PercolationProcess( const PercolationProcess& );

    PercolationProcess& operator=( const PercolationProcess& );

    bool isOpen( Edge ) const { return ((double)rand()/(double)RAND_MAX) < 0.4;}
    bool isOpen( Site ) const  { return((double)rand()/(double)RAND_MAX) < 0.4;} // key
    bool isVisited( Site ) const;
    bool dualX( int i ) const;
    bool dualY( int j ) const;
    bool primalX( int i  ) const;
    bool primalY( int j ) const;
};

#endif
