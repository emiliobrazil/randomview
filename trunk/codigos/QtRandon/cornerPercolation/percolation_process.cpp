#include "percolation_process.hpp"

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
    PercolationProcess tmp( 200, 200 );
    (*this) = tmp;
}

PercolationProcess::PercolationProcess( unsigned int radiusX , unsigned int radiusY ) {

    pRadiusX = radiusX;
    pRadiusY = radiusY;

    const unsigned int size = (pRadiusX + 1) * (pRadiusY + 1);

    for( int i = 0; i <= size; ++i ) {
        pVisitedSites.push_back( false );
        pKeysOfSitesVisited.push_back( false );
    }

    for( int i = 0; i <= pRadiusX; ++i ) {
        pPrimalX.push_back( (rand() / (double) RAND_MAX < 0.5) ? -1 : 1 );
    }

    for( int i = 0; i <= pRadiusY; ++i ) {
        pPrimalY.push_back( (rand() / (double) RAND_MAX < 0.5) ? -1 : 1 );
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

// IMPLEMATATION BEGIN
//bool PercolationProcess::isOpen( Edge edge )
//{
//    Site pos = edge.position();
//    switch ( edge.orientation() )
//    {
//    case H:
//        if ( ( pos.X() + pos.Y() ) % 2 == 0 )
//        {
//            if( dualX( pos.X() ) ) return true;
//            else return false;
//        }
//        else
//        {
//            if( dualX( pos.X() ) ) return false;
//            else return true;
//        }
//        break;
//    case V:
//        if ( ( pos.X() + pos.Y() ) % 2 == 0 )
//        {
//            if( dualY(  pos.Y() ) ) return true;
//            else return false;
//        }
//        else
//        {
//            if( dualY( pos.Y() ) ) return false;
//            else return true;
//        }
//        break;
//    default:
//        return false;
//    }
//}
// IMPLEMATATION END
bool PercolationProcess::isOpen( const Edge& e ) const { return false; }


bool PercolationProcess::isOpen( const Site& s ) const { //return true; } // key

    assert( inBox( s ) );
    return pKeysOfSitesVisited[ getIndex( s ) ];
}

bool PercolationProcess::isVisited( Site s ) const {

    assert( inBox( s ) );
    return pVisitedSites[ getIndex( s ) ];
}

bool PercolationProcess::dualX( int i ) const {

    assert( abs(i) <= pRadiusX );
    return pDualX[  i + pRadiusX  ];
}

bool PercolationProcess::dualY( int j ) const {

   assert( abs(j) <= pRadiusY );
   return pPrimalY[ j + pRadiusY ];
}

bool PercolationProcess::primalX( int i  ) const {

    assert( abs(i) <= pRadiusX );
    return pPrimalX[ i + pRadiusX ];
}

bool PercolationProcess::primalY( int j ) const {

    assert( abs(j) <= pRadiusY );
    return pPrimalY[ j + pRadiusY ];
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

bool PercolationProcess::inBox( const Site &s ) const {

    return (abs(s.X()) <= pRadiusX) && (abs(s.Y()) <= pRadiusY);
}
