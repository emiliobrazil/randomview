
#include "HidrodinamicsParticles.hpp"

HidrodinamicsParticles::HidrodinamicsParticles( uint32 N , FDP function )
{
	this->_particles = std::vector<bool>( N , false );
	real delta = 1.0f / (real)N ;
	real max = function.max() ;

	for( uint32 i = 0 ; i < N ; ++i )
	{
                if( function.eval( i*delta ) >= ( max * uniform01() ) ) this->_particles[i] = true;
	}

        this->_type = ALPHA;
        this->_beta = 1.0;
        this->_betaN = pow( (double)N , -_beta );
        this-> _badSite = 0;

}

HidrodinamicsParticles::HidrodinamicsParticles( uint32 N , FDP function , real beta )
{
        this->_particles = std::vector<bool>( N , false );
        real delta = 1.0f / (real)N ;
        real max = function.max() ;

        for( uint32 i = 0 ; i < N ; ++i )
        {
                if( function.eval( i*delta ) >= ( max * uniform01() ) ) this->_particles[i] = true;
        }

        this->_type = ALPHABETA;
        this->_beta = beta;
        this->_betaN = pow( (double)N , -_beta );
        this->_badSite = _particles.size()/2;

}



HidrodinamicsParticles::~HidrodinamicsParticles( void )
{

}

void HidrodinamicsParticles::visit( uint32 site )
{
    if( this->_particles[site] )
    {
        if( _type == ALPHA )
        {
            normalVisit(site);
        }
        else
        {
            if( _badSite == site || _badSite+1 == site )
            {
                badVisit(site);
            }
            else
            {
                normalVisit(site);
            }
        }
    }
}

void HidrodinamicsParticles::normalVisit( uint32 site )
{
    uint32 N = this->_particles.size();

    uint32 p = bernoulli( 0.5 );
    if( p )
    {
        uint32 NS = ( site + 1 ) % N;
        this->_particles[ site ] = this->_particles[ NS ];
        this->_particles[ NS ] = true;
    }
    else
    {
        uint32 PS = ( (int)site - 1 ) % N;
        this->_particles[ site ] = this->_particles[ PS ];
        this->_particles[ PS ] = true;
    }
}

void HidrodinamicsParticles::badVisit( uint32 site )
{
    uint32 N = this->_particles.size();

    uint32 p = bernoulli( 0.5 );

    if( site == _badSite )
    {
        if( p )
        {
            uint32 b = bernoulli( _betaN );
            if(b)
            {
                uint32 NS = ( site + 1 ) % N;
                this->_particles[ site ] = this->_particles[ NS ];
                this->_particles[ NS ] = true;
            }
        }
        else
        {
            uint32 PS = ( (int)site - 1 ) % N;
            this->_particles[ site ] = this->_particles[ PS ];
            this->_particles[ PS ] = true;
        }
    }
    else
    {
        if( p )
        {
            uint32 NS = ( site + 1 ) % N;
            this->_particles[ site ] = this->_particles[ NS ];
            this->_particles[ NS ] = true;
        }
        else
        {
            uint32 b = bernoulli( _betaN );
            if(b)
            {
                uint32 PS = ( (int)site - 1 ) % N;
                this->_particles[ site ] = this->_particles[ PS ];
                this->_particles[ PS ] = true;
            }
        }
    }
}


ParticlesCounter HidrodinamicsParticles::counter(void)
{
	uint32 N = this->_particles.size();
	ParticlesCounter counter( N );
	for( uint32 i = 0 ; i < N ; ++i )
	{
		if( this->_particles[i] ) counter.set( i , 1.0f );
	}

	return counter;
}
