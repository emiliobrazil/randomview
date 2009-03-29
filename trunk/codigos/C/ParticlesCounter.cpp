#include "ParticlesCounter.hpp"

const ParticlesCounter &ParticlesCounter::operator=( const ParticlesCounter &counter )
{
	ParticlesCounter *tmp = new ParticlesCounter( counter );
	return  *tmp;
}

const ParticlesCounter  ParticlesCounter::operator+( const ParticlesCounter &counter ) const 
{
	uint32 nOp = this->_sites.size();
	ParticlesCounter s( nOp );
	for( uint32 i = 0 ; i < nOp ; ++i)
	{
		s.set( i , this->_sites[i] + counter.get(i) );
	}
	return s;
}

const ParticlesCounter  ParticlesCounter::operator-( const ParticlesCounter &counter ) const 
{
	uint32 nOp = this->_sites.size();
	ParticlesCounter s( nOp );
	for( uint32 i = 0 ; i < nOp ; ++i)
	{
		s.set( i , this->_sites[i] - counter.get(i) );
	}
	return s;
}

const ParticlesCounter  ParticlesCounter::operator*( real alpha ) const
{
	uint32 nOp = this->_sites.size();
	ParticlesCounter p( nOp );
	for( uint32 i = 0 ; i < nOp ; ++i)
	{
		p.set( i , this->_sites[i] * alpha );
	}
	return p;
}

const ParticlesCounter  operator*( real alpha , const ParticlesCounter &counter )
{
	uint32 nOp = counter._sites.size();
	ParticlesCounter p( nOp );
	for( uint32 i = 0 ; i < nOp ; ++i)
	{
		p.set( i , counter._sites[i] * alpha );
	}
	return p;
}

const ParticlesCounter &ParticlesCounter::operator+=( const ParticlesCounter &counter )
{
	uint32 nOp = this->_sites.size();
	for( uint32 i = 0 ; i < nOp ; ++i)
	{
		this->_sites[i] += counter.get(i) ;
	}
	return *this;
}

const ParticlesCounter &ParticlesCounter::operator-=( const ParticlesCounter &counter )
{
	uint32 nOp = this->_sites.size();
	for( uint32 i = 0 ; i < nOp ; ++i)
	{
		this->_sites[i] += counter.get(i) ;
	}
	return *this;
}

const ParticlesCounter &ParticlesCounter::operator*=( real alpha )
{
	uint32 nOp = this->_sites.size();
	for( uint32 i = 0 ; i < nOp ; ++i)
	{
		this->_sites[i] *= alpha ;
	}
	return *this;
}

//  std::vector<real> _sites;
