//--------------------------------------------------------------------------
//Kyle Graham
//Assignment 1
//poly.cpp
//--------------------------------------------------------------------------
#include "poly.h"
#include <iostream>
#include <sstream>
//--------------------------------------------------------------------------
//Poly::Poly()
//default constructor
//--------------------------------------------------------------------------
Poly::Poly()
{
		size = 1;
		storage = new int[1];		//creates 1 storage array and fills
		storage[0] = 0;				//it with one 0 value
}
//--------------------------------------------------------------------------
//Poly::Poly(const Poly &p)
//copy constructor given a Poly
//--------------------------------------------------------------------------
Poly::Poly(const Poly &p)
{
	size = p.size;
	storage = new int[size];
	for(int i = 0; i < size; i++)
		storage[i] = 0;				//clears the storage
	for(int i = 0; i < size; i++)
		storage[i] = p.storage[i];	//fills the storage with p.storage
}
//--------------------------------------------------------------------------
//Poly::Poly(int co, int ex)
//constructor given a coefficient and exponent
//--------------------------------------------------------------------------
Poly::Poly(int co, int ex)
{
	if(ex < 0)			//handles negative exponents
		ex *= -1;
	size = (ex + 1);
	storage = new int[size];
	for(int i = 0; i < size; i++)		//emptys non used portion or storage
		storage[i] = 0;
	storage[ex] = co;
}
//--------------------------------------------------------------------------
//Poly::Poly(int co)
//constructor for one integer coefficient
//--------------------------------------------------------------------------
Poly::Poly(int co)
{
	size = 1;					//adds the coefficient to 0th exponent
	storage = new int[1];		//storage
	storage[0] = co;
}
//--------------------------------------------------------------------------
//Poly::~Poly()
//Destructor function
//--------------------------------------------------------------------------
Poly::~Poly()
{
	delete[] storage;			//deletes memory allocation
	storage = NULL;
}
//--------------------------------------------------------------------------
//int Poly::getCoeff
//returns the coefficient of a given exponent
//--------------------------------------------------------------------------
int Poly::getCoeff(int exp)
{
	if(exp > size - 1 || exp < 0 )		//checks for negative or bigger
		return 0;						//exponents than in storage
	else
		return this->storage[exp];
		
}
//--------------------------------------------------------------------------
//void Poly::setCoeff
//sets the coefficient at a given exponent
//--------------------------------------------------------------------------
void Poly::setCoeff(int coeff, int exp)
{
	if(exp < 0)						//checks for negative exponent
			exp *= -1;
	if(exp > this->size - 1)		//exponent bigger than size
									//needs to increase in size
	{
		Poly temp = *this;
		int newSize = (exp + 1);
		delete[] storage;					//delete old allocation
		this->storage = new int[newSize];	//increase size
		this->size = newSize;
		
		for(int i = exp; i > temp.size - 1; i--)
			this->storage[i] = 0;
		for(int i = 0; i < temp.size; i++)
			this->storage[i] = temp.storage[i];
		this->storage[exp] = coeff;
		
	}
	else                         //exponent smaller than size, just add
								 //coefficient
	{
		this->storage[exp] = 0;
		this->storage[exp] = coeff;
	}
}
//--------------------------------------------------------------------------
//Poly Poly::operator+
//uses + operator
//--------------------------------------------------------------------------
Poly Poly::operator+(const Poly &p)const
{
	Poly temp = *this;
	temp += p;		//uses += instead of rewriting for no reason
	return temp;
}
//--------------------------------------------------------------------------
//Poly Poly::operator-
//uses - operator
//--------------------------------------------------------------------------
Poly Poly::operator-(const Poly &p)const
{
	Poly temp = *this;
	temp -= p;				//uses -= instead of rewriting for no reason
	return temp;
}
//--------------------------------------------------------------------------
//Poly Poly::operator-(int num)
//subtraction between poly and integer
//--------------------------------------------------------------------------
Poly Poly::operator-(int num)
{
	this->storage[0] -= num;	//subtraction on 0th exponent
	return *this;
}
//--------------------------------------------------------------------------
//Poly Poly::operator*
//uses * operator
//--------------------------------------------------------------------------
Poly Poly::operator*(const Poly &p)const
{
	Poly temp = *this;
	temp *= p;			//uses *= instead of rewriting for no reason
	return temp;
}
//--------------------------------------------------------------------------
//Poly& Poly::operator+=
//+= operators for poly
//used in + operator
//--------------------------------------------------------------------------
Poly& Poly::operator+=(const Poly &p)
{
	if(this->size < p.size)			//*this smaller, needs to increase size
	{
		int *temp = new int[p.size];	//temp storage to increase size of
										//*this
		
		for(int i = 0; i < size; i++)
			temp[i] = storage[i];
		for(int i = size; i < p.size; i++)
			temp[i] = 0;
		size = p.size;
		delete[] storage;					//deletes current allocation
		storage = temp;						//puts temp into storage
		temp = NULL;
	}
	for(int i = 0; i < p.size; i++)
		storage[i] = storage[i] + p.storage[i];
	return *this;
}
//--------------------------------------------------------------------------
//Poly& Poly::operator-=
//-= operators for poly
//used in - operator
//--------------------------------------------------------------------------
Poly& Poly::operator-=(const Poly &p)
{
	if(this->size < p.size)				//*this smaller, will need to 
										//increase its size
	{
		int *temp = new int[p.size];	//temp storage to increase p's size
		for(int i = 0; i < size; i++)
			temp[i] = storage[i];
		for(int i = size; i < p.size; i++)	//emptys temp storage
			temp[i] = 0;
		size = p.size;
		delete[] storage;				//deletes current allocation
		storage = temp;					//puts temp storage into *this
		temp = NULL;
	}
	for(int i = 0; i < p.size; i++)
		storage[i] = storage[i] - p.storage[i];
	return *this;	
}
//--------------------------------------------------------------------------
//Poly& Poly::operator*=
//*= operator for poly objects
//used in * operator
//--------------------------------------------------------------------------
Poly& Poly::operator*=(const Poly &p)
{
	int newSize = (size + p.size) - 1;		//adding the exponents + 1
	int *temp = new int[newSize];			//temporary storage
	for(int i = 0; i < newSize; i++)		//emptys temporary storage
		temp[i] = 0;
	for ( int i = size - 1; i >= 0; i--)	//multiplies every coefficient 
	{                                       //and adds the expponents.
		if(storage[i] != 0)                 //skips if coefficient is 0
		{
			for(int j = p.size - 1; j >= 0; j--)
			{
				temp[i+j] += storage[i] * p.storage[j];		
			}	
		}
	}
	size = newSize;
	delete[] storage;						//deletes the allocated storage
	storage = temp;
	temp = NULL;
	return *this;
}
//--------------------------------------------------------------------------
//Poly& Poly::operator=
//assignment operator for poly objects
//--------------------------------------------------------------------------
Poly& Poly::operator=(const Poly &p)
{
	if(this != &p)						//checks if they're already equal
	{
		delete[] storage;				//gets rid of pre existing storage
		storage = NULL;					//from constructors
		size = p.size;
		storage = new int[size];
		for(int i = 0; i < size; i++)	//emptys the storage
			storage[i] = 0;
		for(int i = 0; i < size; i++)	//fills the storage
			storage[i] = p.storage[i];
	}
	return *this;
}
//--------------------------------------------------------------------------
//bool Poly::operator==
//checks if two poly objects are equal
//--------------------------------------------------------------------------
bool Poly::operator==(const Poly &p)
{
	if(this->size != p.size)		//checks the sizes
		return false;
	for(int i = 0; i < size; i++)
	{
		if(this->storage[i] != p.storage[i])	//checks every value in
			return false;						//each storage
	}
	return true;		//passes all checks, equal
}
//--------------------------------------------------------------------------
//bool Poly::operator!=
//checks if two polys are not equal
//uses the == operator
//--------------------------------------------------------------------------
bool Poly::operator!=(const Poly &p)
{
	if(*this == p)		//uses the == operator to test !=
		return false;
	else
		return true;
}
//--------------------------------------------------------------------------
//ostream& operator<<
//outputs a poly object
//--------------------------------------------------------------------------
ostream& operator<<(ostream& sout, const Poly &p)
{
	bool empty = true;		//bool flag for an empty Poly
	for(int i = p.size - 1; i >= 0; i--)
	{
		if(p.storage[i] != 0)	//ignores zero input
		{

			sout << " ";
			if(p.storage[i] >= 0)
				sout << "+";
			if(i == 1)							//outputs for 1st power
				sout << p.storage[i] << "x";
			else if(i == 0)						//outputs for 0th power
				sout << p.storage[i];
			else                                //outputs for any other power
				sout << p.storage[i] << "x^" << i;
			empty = false;
		}
	}
	if(empty)									//empty poly
		sout << "0";
	return sout;
}
//--------------------------------------------------------------------------
//istream& operator>>
//inputs from sin into Poly p
//--------------------------------------------------------------------------
istream& operator>>(istream& sin, Poly &p)
{
	int coef = 0;						//intput variables
	int exp = 0;					
	bool end = false;					//flag for -1 -1 input
	for(int i = 0; i < p.size; i++)		//empty poly for input
		p.storage[i] = 0;
	while(sin >> coef >> exp)			//takes in two integers
	{
		if(coef == -1 && exp == -1)
			break;						//breaks while loop upon -1 -1 input
		else
		{	
			p.setCoeff(coef, exp);		//uses set coefficient to add to 
										//this->storage[]
		}
	}
	return sin;
}