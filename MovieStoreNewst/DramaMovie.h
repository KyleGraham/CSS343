#ifndef _MY_DRAMA
#define _MY_DRAMA

#include "Rental.h"
#include "Movie.h"
// ---------------------- DramaMovie.h ------------------------- 
// Tyler Kowalczik, Kyle Graham  
// CSS343
// Creation Date: 2/29/2016
// Date of Last Modification: 2/29/2016
// ---------------------------------------------------------------- 
// Purpose: Class for drama movies. Inherits from class Movie which
//	inherits from class Rental. This class supports all operations
//	expected of a Rental object.
// ----------------------------------------------------------------
// Special Algorithms:
// - Hashing functions.
// ----------------------------------------------------------------
using namespace std;
class DramaMovie : public Movie 
{
public:
	DramaMovie(int stock, string title, string director, int releaseYear);

	~DramaMovie();
	//returns information about the comedy as formatted output.
	// this includes stock counts
	virtual void print();
	
	virtual bool operator>(const Movie &m) const;
	virtual bool operator>=(const Movie &m) const;
	virtual bool operator==(const Movie &m) const;
private:
	//keeps track of stock for all media types
	
	//actor and release date
};

#endif