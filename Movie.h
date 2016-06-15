// ---------------------- Movie.h ------------------------- 
// Tyler Kowalczik, Kyle Graham  
// CSS343
// Creation Date: 2/29/2016
// Date of Last Modification: 2/29/2016
// ---------------------------------------------------------------- 
// Purpose: Abstract base class different types of movies. Movies
//	are derived from rentals.
// ----------------------------------------------------------------
// Special Algorithms:
// - Hashing functions.
// ----------------------------------------------------------------
//Current num types refers to number of different media types.

#ifndef _MY_MOVIE
#define _MY_MOVIE

#define CURRENT_NUM_TYPES 3
#define PRIME_MOD 31
#define COMMA_SPACE ",   "
#define WHITE_SPACE "  "

using namespace std;
#include "Rental.h"
#include <iostream>

class Movie : public Rental
{
protected:
	//FORWARD DECLARATION OF ENUMS
	//enum types for stock
	enum MediaTypes { vhs, dvd, bd };
	//enum for categories
	enum MovieTypes { F, D, C };
public:
	//enum type to store all types of media.
	Movie();
	Movie(int stock, char movieType, string title, string director, int releaseYear);	//default constructor
	~Movie();	//destructor
	//subtracts one from inventory count of rental
	bool borrow(char type);
	//adds one to inventory count of rental
	void returnRental(char type);
	//returns information about the rental as formatted output.
	// this includes stock counts
	virtual void printRental() {};
	virtual bool operator>(const Movie &m)const {return false;};
	virtual bool operator>=(const Movie &m)const { return false; };
	//bool operator<(const Movie &m) const;
	virtual bool operator==(const Movie &m) const{return false;};
	
	virtual void print(){};
	char getType();
	string getDirector();
	string getTitle();
	int getReleaseYear();
	bool inStock(char mediaType);
protected:
	//keeps track of stock for all media types
	int inventory[CURRENT_NUM_TYPES];
	//category of movie
	char movieType;
	//title of the movie
	string title;
	//director of the movie
	string director;
	//Year movie was released
	int releaseYear;


	int compareTypes(const Movie &m) const;
};

#endif // !_MY_MOVIE
