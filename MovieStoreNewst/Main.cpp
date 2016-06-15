//Tyler Kowalczik, Kyle Graham 
#include "MovieStore.h"
#include "ClassicMovie.h"
#include <iostream>
#include <fstream>


int main()
{
	//opens and reads all the text files
	ifstream movies("data4movies.txt");
	ifstream customers("data4customers.txt");
	ifstream commands("data4commands.txt");
	if (!movies) 
	{
		cout << "File could not be opened." << endl;
		return 1;
	}
	MovieStore a;
	a.initRentals(movies);
	if (!customers)
	{
		cout << "File could not be opened." << endl;
		return 1;
	}
	
	a.initCustomers(customers);
	if (!commands)
	{
		cout << "File could not be opened." << endl;
		return 1;
	}
	a.initCommands(commands);

}