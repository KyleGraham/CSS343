// ---------------------- CustomerHashTable.h ------------------------- 
// Tyler Kowalczik, Kyle Graham  
// CSS343
// Creation Date: 2/29/2016
// Date of Last Modification: 2/29/2016
// ---------------------------------------------------------------- 
// Purpose: Used to map objects to a bucket within the hashtable.
// ----------------------------------------------------------------
// Special Algorithms:
// - Hashing functions.
// ----------------------------------------------------------------
// Assumptions:
// - The hash table stores pointers to objects. This hash class only
//	hashes objects that have implemented the Hashable.h class/interface.
// - This hash class only stores objects that have implemented the 
//	Hashable.h class/interface.
// ----------------------------------------------------------------
#ifndef _MY_HASH_TABLE
#define _MY_HASH_TABLE
#include "Customer.h"

#define MAX_TABLE_SIZE 97

using namespace std;

class CustomerHashTable 
{
	public:
		CustomerHashTable();
		~CustomerHashTable();
		//Inserts a new c into a bucket.
		bool insert(Customer *c);	
		//Marks an c in a bucket as deleted(lazy delete)
		bool remove(int customerID);
		//get method that retrieves current load of hashtable
		double getLoad();	
		int getTableSize();
		bool searchCustomer(int customerID, Customer *&c);
	private:
		//size of the hash table
		int tableSize;
		//Array for hashed items.
		Customer *table[MAX_TABLE_SIZE];
		//Array that marks buckets as empty or non-empty
		//returns true if a bucket is empty
		bool bucketEmpty[MAX_TABLE_SIZE];
		//number of values in the hashtable
		int size;
		//Measures how full the hashtable is.
		double loadFactor;	
		//lazy deletion
		bool deleted;
		int hashCustomer(int customerID);
};

#endif