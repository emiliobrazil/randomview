#include "percolation_process.hpp"
#include <iostream>

PercolationProcess::PercolationProcess( unsigned int radiusX , unsigned int radiusY , double probS )
    : pRadiusX( radiusX ), pRadiusY( radiusY ), pType( CORNER ), pProbS( probS ) {

    const unsigned int size = (2 * radiusX + 1) * (2 * radiusY + 1);

    pKeysOfSitesVisited = new bool[ size ];
    assert( pKeysOfSitesVisited != 0 );

    pVisitedSites = new bool[ size ];
    assert( pVisitedSites != 0 );

    for( unsigned int i = 0; i < size; ++i ) {
        pVisitedSites[ i ] = false;
        pKeysOfSitesVisited[ i ] = false;
    }

    const unsigned int sizeX = (2 * radiusX + 1);

    pPrimalX = new bool[ sizeX ];
    assert( pPrimalX != 0 );
    pDualX = new bool[ sizeX ];
    assert( pDualX != 0 );

    const unsigned int sizeY = (2 * radiusY + 1);

    pPrimalY = new bool[ sizeY ];
    assert( pPrimalY != 0 );
    pDualY = new bool[ sizeY ];
    assert( pDualY != 0 );

    int n, coin, signal;

    for( unsigned int i = 0; i < sizeX; ++i ) {
        coin = uniform01() < 0.5 ? 1 : -1;
        pPrimalX[ i ] = ( coin == 1 );

        n = i - pRadiusX;
        signal = (n + 1) % 2 == 0 ? 1 : -1;
        pDualX[ i ] = ( (signal * coin) == 1 );
    }

    for( unsigned int i = 0; i < sizeY; ++i ) {
        coin = uniform01() < 0.5 ? 1 : -1;
        pPrimalY[ i ] = ( coin == 1 );

        n = i - pRadiusY;
        signal = n % 2 == 0 ? 1 : -1;
        pDualY[ i ] = ( (signal * coin) == 1 );
    }
}

PercolationProcess::~PercolationProcess() {

    delete pVisitedSites;
    delete pKeysOfSitesVisited;
    delete pPrimalX;
    delete pDualX;
    delete pPrimalY;
    delete pDualY;
}

PercolationProcess::PercolationProcess( const PercolationProcess& p )
: pRadiusX( p.pRadiusX ), pRadiusY( p.pRadiusY ), pType( p.pType ), pProbS( p.pProbS ) {

    const unsigned int size = (2 * pRadiusX + 1) * (2 * pRadiusY + 1);

    //delete pKeysOfSitesVisited;
    pKeysOfSitesVisited = new bool[ size ];
    assert( pKeysOfSitesVisited != 0 );

    //delete pVisitedSites;
    pVisitedSites = new bool[ size ];
    assert( pVisitedSites != 0 );

    for( unsigned int i = 0; i < size; ++i ) {
        pVisitedSites[i] = p.pVisitedSites[i];
        pKeysOfSitesVisited[i] = p.pKeysOfSitesVisited[i];
    }

    const unsigned int sizeX = (2 * pRadiusX + 1);

    pPrimalX = new bool[ sizeX ];
    assert( pPrimalX != 0 );
    pDualX = new bool[ sizeX ];
    assert( pDualX != 0 );

    const unsigned int sizeY = (2 * pRadiusY + 1);

    pPrimalY = new bool[ sizeY ];
    assert( pPrimalY != 0 );
    pDualY = new bool[ sizeY ];
    assert( pDualY != 0 );

    for( unsigned int i = 0; i < sizeX; ++i ) {
        pPrimalX[i] = p.pPrimalX[i];
        pDualX[i] = p.pDualX[i];
    }

    for( unsigned int i = 0; i < sizeY; ++i ) {
        pPrimalY[i] = p.pPrimalY[i];
        pDualY[i] = p.pDualY[i];
    }
}

const PercolationProcess& PercolationProcess::operator=( const PercolationProcess& right ) {

    if ( this != &right ) {

        pType = right.pType;
        pProbS = right.pProbS;

        bool change_x = false, change_y = false;

        if ( pRadiusX != right.pRadiusX ) {
            pRadiusX = right.pRadiusX;

            const unsigned int sizeX = (2 * pRadiusX + 1);

            delete pPrimalX;
            pPrimalX = new bool[ sizeX ];
            assert( pPrimalX != 0 );

            delete pDualX;
            pDualX = new bool[ sizeX ];
            assert( pDualX != 0 );

            change_x = true;
        }

        if ( pRadiusY != right.pRadiusY ) {
            pRadiusY = right.pRadiusY;

            const unsigned int sizeY = (2 * pRadiusY + 1);

            delete pPrimalY;
            pPrimalY = new bool[ sizeY ];
            assert( pPrimalY != 0 );

            delete pDualY;
            pDualY = new bool[ sizeY ];
            assert( pDualY != 0 );

            change_y = true;
        }

        if ( change_x && change_y ) {
            const unsigned int size = (2 * pRadiusX + 1) * (2 * pRadiusY + 1);

            delete pKeysOfSitesVisited;
            pKeysOfSitesVisited = new bool[ size ];
            assert( pKeysOfSitesVisited != 0 );

            delete pVisitedSites;
            pVisitedSites = new bool[ size ];
            assert( pVisitedSites != 0 );
        }

        const unsigned int size = (2 * pRadiusX + 1) * (2 * pRadiusY + 1);

        for( unsigned int i = 0; i < size; ++i ) {
            pVisitedSites[i] = right.pVisitedSites[i];
            pKeysOfSitesVisited[i] = right.pKeysOfSitesVisited[i];
        }

        const unsigned int sizeX = (2 * pRadiusX + 1);

        for( unsigned int i = 0; i < sizeX; ++i ) {
            pPrimalX[i] = right.pPrimalX[i];
            pDualX[i] = right.pDualX[i];
        }

        const unsigned int sizeY = (2 * pRadiusY + 1);

        for( unsigned int i = 0; i < sizeY; ++i ) {
            pPrimalY[i] = right.pPrimalY[i];
            pDualY[i] = right.pDualY[i];
        }
    }
    return *this;    
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


bool PercolationProcess::isOpen( Site& s ) const { //return true; } // key

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

bool PercolationProcess::visit( Site &s ) {

    if ( !inBox(s) ) { return false; }

    if ( isVisited(s) ) { return true; }

    pVisitedSites[ getIndex(s) ] = true;
    pKeysOfSitesVisited[ getIndex(s) ] = bernoulli( pProbS );
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

bool PercolationProcess::inBox( Site &s ) const {

    return ((unsigned int)abs(s.X()) <= pRadiusX) && ((unsigned int)abs(s.Y()) <= pRadiusY);
}

unsigned int PercolationProcess::radiusX( void )
{
    return pRadiusX;
}

unsigned int PercolationProcess::radiusY( void )
{
    return pRadiusY;
}
