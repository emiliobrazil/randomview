#include "edge.hpp"
 
Edge::Edge() {
    this -> base.setX(0); 
    this -> base.setY(0); 
    this -> head = H;
} 

Edge::Edge( Site s, ORIENTATION o ) { 
    this -> base = s; 
    this -> head = o; 
}

Edge::Edge( const Edge& e ) { (*this) = e; } 

Edge& Edge::operator=( const Edge& e) { 
    this -> base = e.base; 
    this -> head = e.head; 

    return (*this);
} 

ORIENTATION Edge::orientation( void ) { return head; } 

Site Edge::position( void ) { return base; } 
