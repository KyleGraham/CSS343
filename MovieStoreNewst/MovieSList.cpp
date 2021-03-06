//Tyler Kowalczik, Kyle Graham 
#include "MovieSList.h"
//---------------------------------------------------------------------------
// MovieSList()
// creates the movieslist object
// Preconditions: movieslist object does not exist
// Postconditions: movieslist object is created
// --------------------------------------------------------------------------
MovieSList::MovieSList( ) 
{
	init( );
}
//---------------------------------------------------------------------------
// ~MovieSList()
// deletes the movieslist object
// Preconditions: movieslist object does not exist
// Postconditions: movieslist object is created
// --------------------------------------------------------------------------
MovieSList::~MovieSList()
{
	clear();                                      // delete items starting 1st
	for (int i = 0; i < NUM_LEVELS; i++)
	{
		delete header[i]->next;                      // delete the right most dummy
		delete header[i];                            // delete the left most dummy
	}
}
//---------------------------------------------------------------------------
// init()
// initialization helper for movieslist objects
// Preconditions: empty movieslist object
// Postconditions: movieslist object is created
// --------------------------------------------------------------------------
void MovieSList::init( ) 
{
	for ( int i = 0; i < NUM_LEVELS; i++ ) 
	{  // for each level
    // create the left most dummy nodes;
		header[i] = new MovieNode;
		header[i]->prev = NULL;
		header[i]->down = ( i > 0 ) ? header[i - 1] : NULL;
		header[i]->up = NULL;
		if ( i > 0 ) 
			header[i - 1]->up = header[i];

    // create the right most dummy nodes
		header[i]->next = new MovieNode;
		header[i]->next->next = NULL;
		header[i]->next->prev = header[i];
		header[i]->next->down = ( i > 0 ) ? header[i - 1]->next : NULL;
		header[i]->next->up = NULL;
		if ( i > 0 ) 
			header[i - 1]->next->up = header[i]->next;
	}
}

//---------------------------------------------------------------------------
// clear()
// destructor helper for movieslist objects
// Preconditions: full movieslist object
// Postconditions: empty movieslist object
// --------------------------------------------------------------------------
void MovieSList::clear( ) 
{
	for ( int i = 0; i < NUM_LEVELS; i++ ) 
	{        // for each level
		MovieNode *p = header[i]->next;  // get the 1st c 
		while ( p->next != NULL ) 
		{              // if this is not the left most
			MovieNode *del = p;          
			p = p->next;                           // get the next c
			delete del;                            // delete the current c
		}

    header[i]->next = p;                     // p now points to the left most 
	}                                          // let the right most point to it
}
//---------------------------------------------------------------------------
// insert()
// inserts movie objects into the skip list
// 50% chance to increase the nodes height by 1
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void MovieSList::insert( Movie *r ) {
  // right points to the level-0 c before which a new object is inserted.
 static int counter = 1;
  MovieNode *right = searchPointer( *r );
  MovieNode *upper = NULL;
  MovieNode *lower = NULL;
  if ( right->next != NULL && right->c == r )  
    // there is an identical object
    return;

	MovieNode *newPtr = new MovieNode;
	//insert node
	newPtr->up = NULL;
	newPtr->down = NULL;
	newPtr->c = r; 
	newPtr->next = right;
	newPtr->prev = right->prev;
	right->prev = newPtr;
	newPtr->prev->next = newPtr;
	upper = newPtr;

	//flip coin to see if we need upper values
	int random = rand()%2;
	int counter1 = 0;
	while(random == 1)
	{
		lower = upper;
		right = upper->prev;
		while(right->up == NULL) //find a node with an upper level
		{
			right = right->prev;
		}
		right = right->up;
		if(right->next != NULL)  
			right = right->next;
		//insert node
		upper->up = new MovieNode;
		upper = upper->up;
		upper->up = NULL;
		upper->c = r;
		upper->next = right;
		upper->prev = right->prev;
		right->prev = upper;
		upper->prev->next = upper; //test
		upper->down = lower;
		random = rand()%2;
		//checks to see if the node is at the max level
		if(counter1 == 4)
		{
			random = 0;
			newPtr->up = NULL;
		}	
		counter1++;
	}
}

//---------------------------------------------------------------------------
// searchPointer()
// return a pointer to the c whose value == obj or return
//  a pointer to the first c whose value > obj if we can't find  the exact
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------


MovieNode *MovieSList::searchPointer(Movie &r)
{
	MovieNode *p = header[NUM_LEVELS - 1];     // start from the top left
	while (p->down != NULL)
	{                   // toward level 0
		p = p->down;                                // shift down once

		if (p->prev == NULL)
		{                    // at the left most c
			if (p->next->next == NULL)              // no intermediate items
				continue;
			else
			{                                    // some intermadiate items
				if (r >= *p->next->c)             // if 1st c <= obj
					p = p->next;                          // shift right to c 1
			}
		}
		while (p->next->next != NULL && r >= *p->next->c)
		{
			// shift right through intermediate items as far as the c value <= obj
			p = p->next;
		}
	}
	// now reached the bottom. shift right once if the current c < obj
	if (p->prev == NULL || r > *p->c)
	{
		p = p->next;
	}
	return p; // return the pointer to an c >= a given object.
}
//---------------------------------------------------------------------------
// searchDrama()
// returns true if the drama movie is found and adds the movie to the 
// variable m
// assumptions- if the movie doesnt have enough any stock, the system will say 
// that the movie does not exist.
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
bool MovieSList::searchDrama(char mediaType, string director, string title, DramaMovie *&m)
{
	MovieNode *p = header[0]->next; // at least the right most dummy
	for (; p->next != NULL; p = p->next)
	{
		if (p->c->inStock(mediaType))
		{
			if (p->c->getDirector() == director &&
				p->c->getTitle() == title)
			{
				m = dynamic_cast<DramaMovie*>(p->c);
				return true;
			}
		}
	}
	cout << "Not found" << endl;
	return false;
}
//---------------------------------------------------------------------------
// searchClassic()
// returns true if the classic movie is found and adds the movie to the 
// variable m
// assumptions- if the movie doesnt have enough any stock, the system will say 
// that the movie does not exist.
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
bool MovieSList::searchClassic(char mediaType, int releaseMonth, int releaseYear, string majorFirst, string majorLast, ClassicMovie *&m)
{
	MovieNode *p = header[0]->next; // at least the right most dummy
	for (; p->next != NULL; p = p->next)
	{
		if (p->c->inStock(mediaType))
		{
			ClassicMovie *tmp = dynamic_cast<ClassicMovie*>(p->c);
			if (tmp->getReleaseMonth() == releaseMonth &&
				tmp->getReleaseYear() == releaseYear &&
				tmp->getMajorFirst() == majorFirst &&
				tmp->getMajorLast() == majorLast)
			{
				m = dynamic_cast<ClassicMovie*>(p->c);
				return true;
			}
		}
	}
	cout << "Not found" << endl;
	return false;
}
//---------------------------------------------------------------------------
// searchComedy()
// returns true if the drama movie is found and adds the movie to the 
// variable m
// assumptions- if the movie doesnt have enough any stock, the system will say 
// that the movie does not exist.
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
bool MovieSList::searchComedy(char mediaType, string title, int releaseYear, ComedyMovie *&m)
{
	MovieNode *p = header[0]->next; // at least the right most dummy
	for (; p->next != NULL; p = p->next)
	{
		if (p->c->inStock(mediaType))
		{
			if (p->c->getTitle() == title &&
				p->c->getReleaseYear() == releaseYear)
			{
				m = dynamic_cast<ComedyMovie*>(p->c);
				return true;
			}
		}
	}
	cout << "Not found" << endl;
	return false;
}


//---------------------------------------------------------------------------
// print()
// prints out the contents of the moveslist objects
// Preconditions: NONE
// Postconditions: NONE
// --------------------------------------------------------------------------
void MovieSList::print(char type)
{
	if(type == 'F')
	{
		cout << "-----------------------------------Comedies-----------------------------------" << endl <<
				"Type Stock  Director         Title			 Year  " << endl;
	}
	else if(type == 'D')
	{
		cout << "-----------------------------------Dramas-----------------------------------" << endl <<
		"Type Stock  Director         Title			 Year  "  << endl;
	}
	else if(type == 'C')
	{
		cout << "-----------------------------------Classics-----------------------------------" << endl <<
				"Type Stock  Actor			 Title		Director	 Date  "  << endl;
	}
	else
		cout << "bad movie type" << endl;

	MovieNode *p = header[0]->next; // at least the right most dummy
	for (;p->next != NULL; p = p->next)
	{
			p->c->print();
	}

}