//--------------------------------------------------------------------------
//Kyle Graham
//Assignment 1
//poly.h
//--------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
using namespace std;
class Poly {

	public:
		//constructors
		Poly();
		Poly(int co, int ex);
		Poly(int co);
		Poly(const Poly &p);
		//destructor
		~Poly();

		int getCoeff(int exp);
		void setCoeff(int coeff, int exp);
		
		//friend ostream and istream operators
		friend ostream& operator<<(ostream& sout, const Poly &p);
		friend istream& operator>>(istream& sin, Poly &p);
		//const arithmatic operators
		Poly operator+(const Poly &p)const;
		Poly operator-(const Poly &p)const;
		Poly operator*(const Poly &p)const;

		Poly operator-(int num);
		
		Poly& operator=(const Poly &p);
		Poly& operator+=(const Poly &p);
		Poly& operator-=(const Poly &p);
		Poly& operator*=(const Poly &p);
		//conditional operators
		bool operator==(const Poly &p);
		bool operator!=(const Poly &p);
	private: 
		
		int size;		//size of the poly
		int *storage;	//dynamic array
};