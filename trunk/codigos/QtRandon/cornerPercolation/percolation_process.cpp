#include "percolation_process.hpp"
#include <iostream>

//class PercolationProcess
//{
//private:
//    PERCOLATION pType;
//    std::vector<bool> pPrimalX;
//    std::vector<bool> pPrimalY;
//    std::vector<bool> pDualX;
//    std::vector<bool> pDualY;
//    unsigned int pRadiusX , pRadiusY;
//    std::vector<bool> pVisitedSites;
//    std::vector<bool>  pKeysOfSitesVisited;
//
//public:

/* Implementation */
PercolationProcess::PercolationProcess() {
    PercolationProcess tmp( 500, 500 , 0.5 );
    (*this) = tmp;
}

PercolationProcess::PercolationProcess( unsigned int radiusX , unsigned int radiusY , double probS ) {

    pRadiusX = radiusX;
    pRadiusY = radiusY;
    pType = CORNER;

    pProbS = probS;

    int n, coin, signal;

    const unsigned int size = (pRadiusX + 1) * (pRadiusY + 1);

    for( unsigned int i = 0; i <= size; ++i ) {
        pVisitedSites.push_back( false );
        pKeysOfSitesVisited.push_back( false );
    }

    for( unsigned int i = 0; i < (2*pRadiusX+1); ++i ) {
         coin = ( (double) rand() / (double) RAND_MAX ) < 0.5 ? 1 : -1;
        pPrimalX.push_back( coin == 1 );

        n = i - pRadiusX;
        signal = (n + 1) % 2 == 0 ? 1 : -1;
        pDualX.push_back( (signal * coin) == 1 );
    }

    for( unsigned int i = 0; i < (2*pRadiusY+1); ++i ) {
        coin = ( (double) rand() / (double) RAND_MAX ) < 0.5 ? 1 : -1;
        pPrimalY.push_back( coin == 1 );

        n = i - pRadiusY;
        signal = n % 2 == 0 ? 1 : -1;
        pDualY.push_back( (signal * coin) == 1 );
    }
}

PercolationProcess::PercolationProcess( const PercolationProcess& p ) { (*this) = p; }

PercolationProcess& PercolationProcess::operator=( const PercolationProcess& p ) {

    this -> pType = p.pType;
    this -> pPrimalX = p.pPrimalX;
    this -> pPrimalY = p.pPrimalY;
    this -> pDualX = p.pDualX;
    this -> pDualY = p.pDualY;
    this -> pRadiusX = p.pRadiusX,
    this -> pRadiusY = p.pRadiusY;
    this -> pVisitedSites = p.pVisitedSites;
    this -> pKeysOfSitesVisited = p.pKeysOfSitesVisited;

    return (*this);
}

bool PercolationProcess::isOpen( const Edge& e ) const {

    Site s = e.position();

    switch( e.orientation() ) {

    case H:
        if( dualY( s.Y() ) ) {
            return ( abs( s.X() ) % 2 == 0 ) ? true : false;
        }
        else
        {
            return ( abs( s.X() ) % 2 == 0 ) ? false : true;
        }
        break;

    case V:
        if( dualX( s.X() ) ) {
            return ( abs( s.Y() ) % 2 == 0 ) ? true : false;
        }
        else
        {
            return ( abs( s.Y() ) % 2 == 0 ) ? false : true;
        }
        break;

    default: break;
    }

    return false;
}


bool PercolationProcess::isOpen( const Site& s ) const { //return true; } // key

    assert( inBox( s ) );
    return pKeysOfSitesVisited[ getIndex( s ) ];
}

bool PercolationProcess::isVisited( Site s ) const {

    assert( inBox( s ) );
    return pVisitedSites[ getIndex( s ) ];
}

bool PercolationProcess::dualX( int i ) const {

    return pDualX[ getX(i) ];
}

bool PercolationProcess::dualY( int j ) const {

   return pDualY[ getY(j) ];
}

bool PercolationProcess::primalX( int i  ) const {

    return pPrimalX[ getX(i) ];
}

bool PercolationProcess::primalY( int j ) const {

    return pPrimalY[ getY(j) ];
}

bool PercolationProcess::visit( const Site &s ) {

    if ( !inBox( s ) ) { return false; }

    pVisitedSites[ getIndex(s) ] = true;
    return true;
}

// Helper functions: as long as the box is fixed

unsigned int PercolationProcess::getIndex( const Site& s ) const {

    return ( s.X() + s.Y() * (2 * pRadiusX + 1) + pRadiusX + pRadiusY * (2 * pRadiusX + 1) );
}

unsigned int PercolationProcess::getX( int i ) const {

    assert( (unsigned int)abs(i) <= pRadiusX );
    return ( i + pRadiusX );
}

unsigned int PercolationProcess::getY( int j ) const {

    assert( (unsigned int)abs(j) <= pRadiusY );
    return ( j + pRadiusY );
}

bool PercolationProcess::inBox( const Site &s ) const {

    return ((unsigned int)abs(s.X()) <= pRadiusX) && ((unsigned int)abs(s.Y()) <= pRadiusY);
}
