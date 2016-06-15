//Tyler Kowalczik, Kyle Graham 

#include "Movie.h"
//---------------------------------------------------------------------------
// inStock()
// checks if the movie has inventory, returns true if it does
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool Movie::inStock(char mediaType)
{
	switch (mediaType)
	{
	case 'V':
		if (inventory[vhs] <= 0)
			return false;
		else
			return true;
	case 'D':
		if (inventory[dvd] <= 0)
			return false;
		else
			return true;
	case 'B':
		if (inventory[bd] <= 0)
			return false;
		else
			return true;
	default:
		return false; //invalid mediatype
	}
	return false;
}
//---------------------------------------------------------------------------
// Movie()
// Default constructor for movie objects
// Preconditions: NONE
// Postconditions: Movie object created
// ---------------------------------------------------------------------------
Movie::Movie()
{
	this->inventory[dvd] = 0;
	this->inventory[bd] = 0;
	this->inventory[vhs] = 0;
	this->movieType = ' ';
	this->title = "";
	this->director = "";
	this->releaseYear = 0;
}
//---------------------------------------------------------------------------
// Movie()
// constructor for movie objects
// Preconditions: NONE
// Postconditions: Movie object created
// ---------------------------------------------------------------------------
Movie::Movie(int dvdStock, char movieType, string title, string director, int releaseYear)
{
	if (dvdStock > 0)
		this->inventory[dvd] = dvdStock;
	else
		this->inventory[dvd] = 0;
	this->inventory[bd] = 0;
	this->inventory[vhs] = 0;

	this->movieType = movieType;
	this->title = title;
	this->director = director;
	this->releaseYear = releaseYear;
}
//---------------------------------------------------------------------------
// ~Movie()
// Destructor for movie objects
// Preconditions: Movie object exists
// Postconditions: Movie object deleted
// ---------------------------------------------------------------------------
Movie::~Movie()
{
	this->inventory[dvd] = 0;
	this->inventory[bd] = 0;
	this->inventory[vhs] = 0;
	this->movieType = ' ';
	this->title = "";
	this->director = "";
	this->releaseYear = 0;
	delete this;
}
//---------------------------------------------------------------------------
// borrow()
// checks if the movie has stock, and borrows (-1 inventory) the movie
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool Movie::borrow(char type)
{
	switch (type) {
	case 'V':
		if (inventory[vhs] > 0) {
			inventory[vhs] -= 1;
			return true;
		}
		else
			return false;
	case 'D':
		if (inventory[dvd] > 0) {
			inventory[dvd] -= 1;
			return true;
		}
		else
			return false;
	case 'B':
		if (inventory[bd] > 0) {
			inventory[bd] -= 1;
			return true;
		}
		else
			return false;
	default:
		cout << "Meh! Input.";
		return false; //bad input
	}
}
//---------------------------------------------------------------------------
// returnRental()
// checks if the movie has stock, and borrows (-1 inventory) the movie
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
void Movie::returnRental(char type)
{
	switch (type)
	{
	case 'V':
		inventory[vhs] += 1;
	case 'D':
		inventory[dvd] += 1;
	case 'B':
		inventory[bd] += 1;
	default:
		cout << "Meh! Input.";
	}
}
//---------------------------------------------------------------------------
// compareTypes()
// return negative if less than
// return 0 if equal
// return positive if greater than
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
int Movie::compareTypes(const Movie & m) const
{
	int lhs = MovieTypes(this->movieType);
	int rhs = MovieTypes(m.movieType);

	if (lhs > rhs)
		return 1;
	else if (lhs < rhs)
		return -1;
	else
		return 0;
}
//---------------------------------------------------------------------------
// getType()
// returns the type of the movie
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
char Movie::getType()
{
	return this->movieType;
}
//---------------------------------------------------------------------------
// getDirector()
// returns the director of the movie
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
string Movie::getDirector()
{
	return this->director;
}
//---------------------------------------------------------------------------
// getTitle()
// returns the title of the movie
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
string Movie::getTitle()
{
	return this->title;
}
//---------------------------------------------------------------------------
// getReleaseYear()
// returns the release year of the movie
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
int Movie::getReleaseYear()
{
	return releaseYear;
}
