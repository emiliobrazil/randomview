#ifndef _PARTICLESCOUNTER_HPP_
#define _PARTICLESCOUNTER_HPP_

#include <vector>
#include <iostream>

#include "primitive_types.h"


class ParticlesCounter
{
public:
	ParticlesCounter( uint32 N ) { this->_sites = std::vector<real>( N , 0.0 ); }
	ParticlesCounter( const ParticlesCounter& counter ) { this->_sites = counter.vector(); }

	~ParticlesCounter( void ){}

	const std::vector<real>& vector( void ) const { return this->_sites ; }
	uint32 size( void ){ return this->_sites.size(); }

	inline real at( uint32 i ){ return this->_sites[i] ; }
	inline void set( uint32 i , real x ){ this->_sites[i] = x ; }
        inline real get( uint32 i ) const { return this->_sites[i] ; }

	const ParticlesCounter &operator=( const ParticlesCounter &counter ) ;
	const ParticlesCounter  operator+( const ParticlesCounter &counter ) const;
	const ParticlesCounter  operator-( const ParticlesCounter &counter ) const ;
	const ParticlesCounter  operator*( real alpha ) const ;
	friend const ParticlesCounter  operator*( real alpha , const ParticlesCounter &counter );
	const ParticlesCounter &operator*=( real alpha );
	const ParticlesCounter &operator+=( const ParticlesCounter &counter );
	const ParticlesCounter &operator-=( const ParticlesCounter &counter );

	void print( void );

private:
	std::vector<real> _sites;

};

#endif // _PARTICLESCOUNTER_HPP_

