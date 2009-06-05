
MAIN
Site start( 0 , 0 );
Particle particle( start );
PercolationProcess cornerPercolation( 500, 500 );
Path path( start );
while( !path.isClosed()  && !particle.isOutBox() )
{
	goNextPosition( cornerPercolation );
	path.add( particle.position() );
}


enum ORIENTATION { H , V }
enum PERCOLATION { CORNER }

class Site:
{
private:
	int pPosition[2];

public:
	Site(  int x ,  int y );
	int X( void );
	int Y( void );
	void setX( int x );
	void setY( int Y );
	void addX( int step );
	void addY( int step );
}

class Edge:
{
private:
	Site pPosition;
	ORIENTATION pOri;
public:
	Edge( Site position , ORIENTATION ori );
	ORIENTATION orientation( void );
	Site position( void );
}


class PercolationProcess
{
private:
	PERCOLATION pType = CORNER;
	std::vector<bool> pPrimalX;
	std::vector<bool> pPrimalY;
	std::vector<bool> pDualX;
	std::vector<bool> pDualY;
	uint32 pRadiusX , pRadiusY;
	std::vector<Site> pVisitedSites;
	std::vector<bool>  pKeysOfSitesVisited;

public:
	PercolationProcess( unsigned int radiusX , unsigned int radiusY );
	
	bool isOpen( Edge );
	bool isOpen( Site ); // key
	bool isVisited( site );
	bool dualX( int i );
	bool dualY( int j );
	bool primalX( int i  );
	bool primalY( int j );
}

// IMPLEMATATION BEGIN
bool PercolationProcess::isOpen( Edge edge )
{
	Site pos = edge.position();
	switch ( edge.orientation() )
	case H:
		if ( ( pos.X() + pos.Y() ) % 2 = 0 )
		{
			if( dualX( pos.X() ) ) return true;
			else false;
		}
		else
		{
			if( dualX( pos.X() ) ) return false;
			else true;
		}
		break
	case V:
		if ( ( pos.X() + pos.Y() ) % 2 = 0 )
		{
			if( dualY(  pos.Y() ) ) return true;
			else false;
		}
		else
		{
			if( dualY( pos.Y() ) ) return false;
			else true;
		}
	default:
		return false;
}
// IMPLEMATATION END


class Path:
{
private:
	std::vector<Site> pPath;
	bool pIsClosed;

public:
	Path( Site startPosition );
	unsigned int size( void );
	bool isInPath( Site );
	void add( Site );
	bool isClosed;
}

class Particle:
{
private:
	ORIENTATION pOri;
	Site pActualPosition;
public:
	Particle( Site startPosition );
	Site goNextPosition( const PercolationProcess& percolation );
	bool isOutBox( void );
	Site position( void );
}

// IMPLEMATATION BEGIN
Site Particle::goNextPosition( const PercolationProcess& percolation )
{
	if( !isOutBox )
	{
		switch (this->pOri)
		case H:
			int step = ( percolation.primalY( pActualPosition.Y() ) ) ? 1 : -1 ;
			pActualPosition.addX( step );
			pOri = ( percolation.isOpen( position() )  ) ? H : V ;
			break;
		case V:
			int step = ( percolation.primalX( pActualPosition.X() ) ) ? 1 : -1 ;
			pActualPosition.addY( step );
			pOri = ( percolation.isOpen( position() )  ) ? V : H ;
			break;
		default:
			break;
	}
	return position();
}

// IMPLEMATATION END

