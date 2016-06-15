//Tyler Kowalczik, Kyle Graham 
#include "ClassicMovie.h"
//---------------------------------------------------------------------------
// ClassicMovie()
// creates a classicmovie object
// Preconditions: NONE
// Postconditions: created classicmovie object
// ---------------------------------------------------------------------------
ClassicMovie::ClassicMovie(int stock, string title, string director, 
	string majorFirst, string majorLast, int releaseMonth, int releaseYear)
	
{
	this->majorFirst = majorFirst;
	this->majorLast = majorLast;
	this->releaseMonth = releaseMonth;
	this->inventory[dvd] = stock;
	this->title = title;
	this->director = director;
	this->releaseYear = releaseYear;
	this->movieType = 'C';
}


//---------------------------------------------------------------------------
// ~ClassicMovie()
// creates a classicmovie object
// Preconditions: full classicmovie object
// Postconditions: deleted classicmovie object
// ---------------------------------------------------------------------------
ClassicMovie::~ClassicMovie()
{
	delete this;
}
//---------------------------------------------------------------------------
// print()
// prints the contents of a classic movie object
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
void ClassicMovie::print()
{
	cout << "C" << COMMA_SPACE << inventory[dvd] << COMMA_SPACE
		<< director << COMMA_SPACE << title << COMMA_SPACE
		<< majorFirst << WHITE_SPACE << majorLast << WHITE_SPACE 
		<< releaseMonth << WHITE_SPACE << releaseYear << endl;
}
//---------------------------------------------------------------------------
// operator>()
// checks if a classicmovie object is greater than another classicmovie object
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool ClassicMovie::operator>(const Movie &m)const
{
	//casts a movie object into a classicmovie
	const ClassicMovie& c = static_cast<const ClassicMovie&>(m);
	if (this->releaseYear < c.releaseYear)
		return false;
	//temp2 is smaller
	else if (this->releaseYear > c.releaseYear)
		return true;
	else
	{
		if (this->releaseMonth < c.releaseMonth)
			return false;
		//temp2 is smaller
		else if (this->releaseMonth > c.releaseMonth)
			return true;
		else
		{
			string temp = this->majorFirst;
			string temp2 = c.majorFirst;
			int compare = temp.compare(temp2);
			if (compare < 0)
				return false;
			//temp2 is smaller
			else if (compare > 0)
				return true;
			else
			{
				temp = this->majorLast;
				temp2 = c.majorLast;
				compare = temp.compare(temp2);
				if (compare <= 0)
					return false;
				else
					return true;
			}
		}
	}
}
//---------------------------------------------------------------------------
// operator>=()
// checks if a classicmovie object is greater than or equal to another 
// classicmovie object
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool ClassicMovie::operator>=(const Movie & m) const
{
	//casts the movie object into a classicmovie
	const ClassicMovie& c = static_cast<const ClassicMovie&>(m);
	if (this->releaseYear < c.releaseYear)
		return false;
	//temp2 is smaller
	else if (this->releaseYear > c.releaseYear)
		return true;
	else
	{
		if (this->releaseMonth < c.releaseMonth)
			return false;
		//temp2 is smaller
		else if (this->releaseMonth > c.releaseMonth)
			return true;
		else
		{
			string temp = this->majorFirst;
			string temp2 = c.majorFirst;
			int compare = temp.compare(temp2);
			if (compare < 0)
				return false;
			//temp2 is smaller
			else if (compare > 0)
				return true;
			else
			{
				temp = this->majorLast;
				temp2 = c.majorLast;
				compare = temp.compare(temp2);
				if (compare < 0)
					return false;
				else
					return true;
			}
		}
	}
}
//---------------------------------------------------------------------------
// operator==()
// checks if a classicmovie object is equal to another classicmovie object
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool ClassicMovie::operator==(const Movie &m)const
{
	//casts the movie object to a classicmovie
	const ClassicMovie& c = static_cast<const ClassicMovie&>(m);
	if (this->releaseMonth != c.releaseMonth)
		return false;
	else
	{
		if (this->releaseYear != c.releaseYear)
			return false;
		else
		{
			string temp = this->majorFirst;
			string temp2 = c.majorFirst;
			int compare = temp.compare(temp2);
			if (compare != 0)
				return false;
			else
			{
				temp = this->majorLast;
				temp2 = c.majorLast;
				compare = temp.compare(temp2);
				if (compare != 0)
					return false;
				else
					return true;
			}	
		}
	}
}
//---------------------------------------------------------------------------
// getReleaseMonth()
// returns the releaseMonth
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
int ClassicMovie::getReleaseMonth()
{
	return releaseMonth;
}
//---------------------------------------------------------------------------
// getMajorFirst()
// returns the major actors first name
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
string ClassicMovie::getMajorFirst()
{
	return majorFirst;
}
//---------------------------------------------------------------------------
// getMajorLast()
// returns the major actors last name
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
string ClassicMovie::getMajorLast()
{
	return majorLast;
}


