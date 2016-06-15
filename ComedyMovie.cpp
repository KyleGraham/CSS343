//Tyler Kowalczik, Kyle Graham 
#include "ComedyMovie.h"
//---------------------------------------------------------------------------
// ComedyMovie()
// creates a comedymovie object
// Preconditions: NONE
// Postconditions: created comedymovie object
// ---------------------------------------------------------------------------
ComedyMovie::ComedyMovie(int stock, string title, string director, int releaseYear)

{
	this->inventory[dvd] = stock;
	this->title = title;
	this->director = director;
	this->releaseYear = releaseYear;
	this->movieType = 'F';
	
}
//---------------------------------------------------------------------------
// ~ComedyMovie()
// creates a comedymovie object
// Preconditions: full comedymovie object
// Postconditions: deleted comedymovie object
// ---------------------------------------------------------------------------
ComedyMovie::~ComedyMovie()
{
	delete this;
}
//---------------------------------------------------------------------------
// print()
// prints the contents of a comedy movie object
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
void ComedyMovie::print()
{
	cout << "F" << COMMA_SPACE << inventory[dvd] << COMMA_SPACE
		<< director << COMMA_SPACE << title << COMMA_SPACE
		<< releaseYear << endl;
}
//---------------------------------------------------------------------------
// operator>()
// checks if a comedymovie object is greater than another comedymovie object
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool ComedyMovie::operator>(const Movie &m) const
{
	const ComedyMovie& c = static_cast<const ComedyMovie&>(m);
	string temp = this->title;
	string temp2 = c.title;
	int compare = temp.compare(temp2);
	if (compare < 0)
		return false;
	//temp2 is smaller
	else if (compare > 0)
		return true;
	else
	{
		if (this->releaseYear <= c.releaseYear)
			return false;
		else
			return true;
	}
}
//---------------------------------------------------------------------------
// operator>=()
// checks if a comedymovie object is greater than or equal to another 
// comedymovie object
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool ComedyMovie::operator>=(const Movie & m) const
{
	const ComedyMovie& c = static_cast<const ComedyMovie&>(m);
	string temp = this->title;
	string temp2 = c.title;
	int compare = temp.compare(temp2);
	if (compare < 0)
		return false;
	//temp2 is smaller
	else if (compare > 0)
		return true;
	else
	{
		if (this->releaseYear < c.releaseYear)
			return false;
		else
			return true;
	}
}
//---------------------------------------------------------------------------
// operator==()
// checks if a comedymovie object is equal to another comedymovie object
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool ComedyMovie::operator==(const Movie &m) const
{
	const ComedyMovie& c = static_cast<const ComedyMovie&>(m);
	string temp = this->title;
	string temp2 = c.title;
	int compare = temp.compare(temp2);
	if (compare != 0)
		return false;
	//temp2 is smaller
	else 
	{
		if (this->releaseYear != c.releaseYear)
			return false;
		else
			return true;
	}
}
