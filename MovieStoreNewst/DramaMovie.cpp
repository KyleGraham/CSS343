//Tyler Kowalczik, Kyle Graham 
#include "DramaMovie.h"
//---------------------------------------------------------------------------
// DramaMovie()
// creates a dramamovie object
// Preconditions: NONE
// Postconditions: created dramamovie object
// ---------------------------------------------------------------------------
DramaMovie::DramaMovie(int stock, string title, string director, int releaseYear)

{
	this->inventory[dvd] = stock;
	this->title = title;
	this->director = director;
	this->releaseYear = releaseYear;
	this->movieType = 'D';
}

//---------------------------------------------------------------------------
// ~DramaMovie()
// creates a dramamovie object
// Preconditions: full dramamovie object
// Postconditions: deleted dramamovie object
// ---------------------------------------------------------------------------
DramaMovie::~DramaMovie()
{
	delete this;
}
//---------------------------------------------------------------------------
// operator>()
// checks if a dramamovie object is greater than another dramamovie object
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool DramaMovie::operator>(const Movie &m) const
{
	if (compareTypes(m) == 0)
	{
		
		const DramaMovie& d = static_cast<const DramaMovie&>(m);
		string temp = this->director;
		string temp2 = d.director;
		int compare = temp.compare(temp2);
		if (compare < 0)
			return false;
		//temp2 is smaller
		else if (compare > 0)
			return true;
		else if (compare == 0)
		{
			temp = this->title;
			temp2 = d.title;
			compare = temp.compare(temp2);
			if (compare <= 0)
				return false;
			//temp2 is smaller
			else
				return true;
		}
	}
	else if (compareTypes(m) > 0)
		return true;
	else
		return false;
	return false;
}
//---------------------------------------------------------------------------
// operator>=()
// checks if a dramamovie object is greater than or equal to another 
// dramamovie object
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool DramaMovie::operator>=(const Movie & m) const
{
	if (compareTypes(m) == 0)
	{

		const DramaMovie& d = static_cast<const DramaMovie&>(m);
		string temp = this->director;
		string temp2 = d.director;
		int compare = temp.compare(temp2);
		if (compare < 0)
			return false;
		//temp2 is smaller
		else if (compare > 0)
			return true;
		else if (compare == 0)
		{
			temp = this->title;
			temp2 = d.title;
			compare = temp.compare(temp2);
			if (compare < 0)
				return false;
			//temp2 is smaller
			else
				return true;
		}
	}
	else if (compareTypes(m) > 0)
		return true;
	else
		return false;
	return false;
}
//---------------------------------------------------------------------------
// operator==()
// checks if a dramamovie object is equal to another dramamovie object
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool DramaMovie::operator==(const Movie &m) const
{
	const DramaMovie& d = static_cast<const DramaMovie&>(m);
	if (compareTypes(m) == 0)
	{
		
		string temp = this->director;
		string temp2 = d.director;
		int compare = temp.compare(temp2);
		if (compare != 0)
			return false;
		//temp2 is smaller
		else
		{
			temp = this->title;
			temp2 = d.title;
			compare = temp.compare(temp2);
			if (compare != 0)
				return false;
			//temp2 is smaller
			else
				return true;
		}
	}
	else
		return false;
}
//---------------------------------------------------------------------------
// print()
// prints the contents of a drama movie object
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
void DramaMovie::print()
{
	cout << "D" << COMMA_SPACE << inventory[dvd] << COMMA_SPACE 
		<< director << COMMA_SPACE << title << COMMA_SPACE
		<< releaseYear << endl;
}
