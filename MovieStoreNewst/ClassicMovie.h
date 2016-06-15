#ifndef _MY_CLASSIC
#define _MY_CLASSIC

#include "Rental.h"
#include "Movie.h"
// ---------------------- ClassicMovie.h ------------------------- 
// Tyler Kowalczik, Kyle Graham  
// CSS343
// Creation Date: 2/29/2016
// Date of Last Modification: 2/29/2016
// ---------------------------------------------------------------- 
// Purpose: Class for classic movies. Inherits from class Movie which
//	inherits from class Rental. This class supports all operations
//	expected of a Rental object.
// ----------------------------------------------------------------
// Special Algorithms:
// - Hashing functions.
// ----------------------------------------------------------------
class ClassicMovie : public Movie
{
public:
	ClassicMovie(int stock, string title, string Director,
		string majorFirst, string majorLast, int releaseMonth, int releaseYear);		//default constructor
	~ClassicMovie();	//destructor
	//returns information about the classic as formatted output.
	// this includes stock counts
	virtual void print();
	virtual bool operator>(const Movie &m) const;
	virtual bool operator>=(const Movie &m) const;
	virtual bool operator==(const Movie &m) const;
	int getReleaseMonth();
	string getMajorFirst();
	string getMajorLast();
protected:
	int releaseMonth;
	string majorFirst;
	string majorLast;
};

#endif