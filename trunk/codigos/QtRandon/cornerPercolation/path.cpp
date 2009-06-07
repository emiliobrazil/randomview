#include "path.hpp"

//    std::vector<Site> pPath;
//    std::vector<Site>::iterator iterator;
//
//    bool pIsClosed;

Path::Path( void )
{
    Site s;
    this -> pPath.push_back( s );
    this -> iterator = pPath.begin();
    this -> pIsClosed = false;
}

Path::Path( const Site& startPosition )
{
    this -> pPath.push_back( startPosition );
    this -> iterator = pPath.begin();
    this -> pIsClosed = false;
} 

Path::Path( const Path&p )
{
    (*this) = p;
}

Path& Path::operator=( const Path& p )
{
    this -> pPath = p.pPath;
    this -> iterator = p.iterator;
    this -> pIsClosed = p.pIsClosed;

    return (*this);
}

unsigned int Path::size( void ) { return this -> pPath.size(); } 

bool Path::isInPath( const Site& s ) {

    std::vector<Site>::iterator i;
    i = this -> iterator;

    bool isInPath = false; 

    for( unsigned int j = 0; j <= pPath.size() && !isInPath; ++j ) {
	if ( *i == s ) { isInPath = true; }
	++i;
    }

    return isInPath;
}

void Path::add( const Site& s ) { this -> pPath.push_back( s ); }

bool Path::isClosed( void ) const { return pIsClosed; } 

const Site& Path::getSite( int index ) const { return this->pPath[index]; }
