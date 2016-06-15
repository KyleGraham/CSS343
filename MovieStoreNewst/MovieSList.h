#ifndef _RENTAL_SLIST
#define _RENTAL_SLIST

#include <iostream>
#include <cstdlib>
#include "Movie.h"
#include "ClassicMovie.h"
#include "DramaMovie.h"
#include "ComedyMovie.h"

// ---------------------- MovieSList.h ------------------------- 
// Tyler Kowalczik, Kyle Graham  
// CSS343
// Creation Date: 2/29/2016
// Date of Last Modification: 2/29/2016
// ---------------------------------------------------------------- 
// Purpose: template skip list class that stores any type of 
//	rental object.
// ----------------------------------------------------------------
// Special Algorithms:
// - Insertions use a probability based approach to promoting
//	nodes to higher levels on the skip list.
// - Insertions and deletions must pay careful attention that all
//	links in the chain are appropriately established after an 
//	operation.
// ----------------------------------------------------------------
#define NUM_LEVELS 6
using namespace std;

//Sructure used for nodes of skip list
struct MovieNode
{
		Movie *c;
		MovieNode *prev;
		MovieNode *next;
		MovieNode *up;
		MovieNode *down;
	};


class MovieSList {
	
public:
	MovieSList();	//default constructor
	~MovieSList();	//destructor
	//inserts a rental object into list. Uses a 50%
	//probability to determine whether or not to promote
	//a rental object to a higher level linked list.
	void insert(Movie *r);
	//removes a rental object in the list
	
	//searches for a rental object within the list.
	
	//returns a formatted string of all rentals
	//within the list.
	
	

	void clear();
	//prints out the contents of the slist
	void print(char type);
	//searches through to find a type a specific type of movie from the slist
	bool searchClassic(char mediaType, int releaseMonth, int releaseYear, string majorFirst, string majorLast, ClassicMovie *&m);
	bool searchDrama(char mediaType, string director, string title, DramaMovie *&m);
	bool searchComedy(char mediaType, string title, int releaseYear, ComedyMovie *&m);
private:	
	//skip list full of rental items w/ NUM_LEVELS
	MovieNode *SList[NUM_LEVELS];
protected:
  MovieNode *header[NUM_LEVELS]; // header
  void init( );                     // called from the above two constructors
  MovieNode *searchPointer(Movie &r); // used by find
};

#endif

//NOTE TO KYLE FROM TYLER!!!!!! 
//if a movie object exists in the skip list, we need to return a pointer
//to said movie object so that we can call the borrow() method on it.