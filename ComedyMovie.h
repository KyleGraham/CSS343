#ifndef _MY_COMEDY
#define _MY_COMEDY

#include "Rental.h"
#include "Movie.h"
// ---------------------- ComedyMovie.h ------------------------- 
// Tyler Kowalczik, Kyle Graham  
// CSS343
// Creation Date: 2/29/2016
// Date of Last Modification: 2/29/2016
// ---------------------------------------------------------------- 
// Purpose: Class for comedy movies. Inherits from class Movie which
//	inherits from class Rental. This class supports all operations
//	expected of a Rental object.
// ----------------------------------------------------------------
// Special Algorithms:
// - Hashing functions.
// ----------------------------------------------------------------
using namespace std;
class ComedyMovie : public Movie 
{
	friend ostream & operator<<(ostream& out, const ComedyMovie& r);
public:
	ComedyMovie(int stock, string title, string director, int releaseYear);
	
	~ComedyMovie();
	//returns information about the comedy as formatted output.
	// this includes stock counts
	virtual void print();
	
	virtual bool operator>(const Movie &m) const;
	virtual bool operator>=(const Movie &m) const;
	virtual bool operator==(const Movie &m) const;
};

#endif