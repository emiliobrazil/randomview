#include "path.hpp"

//    std::vector<Site> pPath;
//    std::vector<Site>::iterator iterator;
//
//    bool pIsClosed;

Path::Path( void ) : pIsClosed(false) {}

Path::Path( const Site& startPosition )
    : pIsClosed(false)
{
    add(startPosition);
} 

// TODO
Path::Path( const Edge& startPosition ) { }

Path::Path( const Path&p )
{
    this -> pIsClosed = false;

    unsigned int size = p.size();

    for ( int i = 0; i < size; ++i ) {
        add(p.getSite(i));
    }
}

Path& Path::operator=( const Path& p )
{
    this -> pIsClosed = false;
    this -> pPath.clear();
    this -> tail_path.clear();

    unsigned int size = p.size();

    for ( int i = 0; i < size; ++i ) {
        add(p.getSite(i));
    }    

    return (*this);
}

unsigned int Path::size( void ) const { return this -> pPath.size(); }

bool Path::isInPath( const Site& s ) {

/*    std::vector<Site>::iterator i;
    i = this -> iterator;*/

    bool isInPath = false; 

    for( unsigned int i = 0; i <= pPath.size() && !isInPath; ++i ) {
        if ( pPath[i] == s ) { isInPath = true; }
    }

    return isInPath;
}

void Path::add( const Site& s ) {
    this -> pPath.push_back( s );

    unsigned int size = pPath.size();
    if ( size > 1 ) {

        std::pair<std::set<Edge, less>::iterator, bool> it_pair;
        Edge e( head_site, getHead( head_site, s ) );

        it_pair = tail_path.insert( e );
        if( it_pair.second == false ) { pIsClosed = true; }
    }
    head_site = s;
}

// TODO: turn this mess into readable code

// first define a partial order (lexicographic) on the edges
// return true if e1 < e2, false otherwise
//struct less {
//    bool operator()( const Edge& e1, const Edge& e2 ) const {
//        int dx = 0, dy = 0;
//        bool dO;
//
//        dx = e1.position().X() - e2.position().X();
//        dy = e1.position().Y() - e2.position().Y();
//        dO = e1.orientation() == H && e2.orientation() == V ? true : false;
//
//        if ( dx < 0 ) { return true; }
//        else if ( dx == 0 && dy < 0 ) { return true; }
//        else if ( dy == 0 && dO ) { return true; }
//
//        return false;
//    }
//};

// beware with the last Site in Path: possible logical error in Path::isClosed( void )
bool Path::isClosed( void ) {

//    if( !pIsClosed && !pPath.empty() ) {
//
//        // Make a set
//        std::set<Edge, less> bag;
//        std::pair<std::set<Edge, less>::iterator, bool> it_pair;
//
//        Site s_base( pPath[0] ), s_head;
//
//        // Insert the edges into the set
//        for( unsigned int i = 1; i < pPath.size(); ++i ) {
//
//            s_head = pPath[i];
//            Edge edge( s_base, getHead(s_base, s_head) );
//            it_pair = bag.insert(edge);
//            s_base = s_head;
//
//            if( it_pair.second == false ) { pIsClosed = true; }
//        }
//    }
    return pIsClosed;
}

const Site& Path::getSite( int index ) const { return this->pPath[index]; }

// helper functions
ORIENTATION Path::getHead( const Site& a, const Site& b ) const {

    int dx = 0, dy = 0;

    dx = a.X() - b.X();
    dy = a.Y() - b.Y();

    // just checks we are in a box with radius 1
    assert( -1 <= dx && dx <= 1 );
    assert( -1 <= dy && dy <= 1 );

    // now checks either a and b are note equal and are neighbours
    assert( (dx || dy) != 0 && dx * dy == 0 );

    return (dx == 0) ? V : H;
}
