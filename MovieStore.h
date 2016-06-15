#include "Customer.h"
#include "CustomerHashTable.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "Movie.h"
#include "MovieSList.h"
#include <fstream>
#include <sstream>


// ---------------------- MovieStore.h ------------------------- 
// Tyler Kowalczik, Kyle Graham  
// CSS343
// Creation Date: 2/29/2016
// Date of Last Modification: 2/29/2016
// ---------------------------------------------------------------- 
// Purpose: This class is an abstract data type for a movie store.
//	Its responsiblity is to manage inentory and customer information.
// ----------------------------------------------------------------
// Special Algorithms:
// - Skip list is used for inserting different rentals into a sorted 
//	linked list.
// ----------------------------------------------------------------
// Assumptions:
// - If a user of this program wishes to extend its design for new
//	kinds of rentals, they will have to create a new hashtable
//	and a new skip list for the new rental.
// - Invalid inputs are not parsed. The user is notified of
//	invalid inputs when they occur.
// - A skip list is used to store different types of rentals in
//	sorted order (skip list offers quicker access
//	for insertions and deletions). 
// ----------------------------------------------------------------
using namespace std;
class MovieStore {
public:
	//Default constructor.
	MovieStore();
	//Default destructor.
	~MovieStore();
	////Initializes all rentals from a formatted text file
	void initRentals(ifstream& input);
	////Initializes all customers from a formatted text file
	void initCustomers(ifstream& input);
	void initCommands(ifstream& input);
	
	
private:
	int numCustomers;
	////open address hash table for customer objects.
	
	////open address hash table for rental type objects.
	CustomerHashTable customers;
	////Skip list of classic movies. Used to print comedies in sorted order.
	MovieSList ClassicList;	
	//////Skip list of drama movies. Used to print dramas in sorted order.
	MovieSList DramaList;		
	//////Skip list of comedy movies. Used to print classics in sorted order.
	MovieSList ComedyList;	
};
