//Tyler Kowalczik, Kyle Graham 
#include "CustomerHashTable.h"
//---------------------------------------------------------------------------
// CustomerHashTable()
// default constructor for CustomerHashTable objects
// Preconditions: NONE
// Postconditions: CustomerHashTable object created
// ---------------------------------------------------------------------------
CustomerHashTable::CustomerHashTable()
{
	this->size = 0;
	this->tableSize = MAX_TABLE_SIZE;

	for (int i = 0; i < MAX_TABLE_SIZE; i++)
	{
		bucketEmpty[i] = true;
		table[i] = NULL;
	}
}
//---------------------------------------------------------------------------
// ~CustomerHashTable()
// destructor for CustomerHashTable objects
// Preconditions: CustomerHashTable object exists
// Postconditions: CustomerHashTable object deleted
// ---------------------------------------------------------------------------
CustomerHashTable::~CustomerHashTable()
{
	for (int i = 0; i < tableSize; i++)
	{
		if (table[i] != NULL) 
		{
			delete table[i];
			table[i] = NULL;
		}
	}
	delete *table;
}
//---------------------------------------------------------------------------
// insert()
// inserts a customer object into the customerhashtable object
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool CustomerHashTable::insert(Customer *c)
{
	int key = hashCustomer(c->getID());
	int i = 1;
	while (table[key] != NULL)
	{
		key = (key + (i * i) % tableSize);
		i++;
	}
	table[key] = c;
	bucketEmpty[key] = false;
	this->size += 1;
	return true;
}
//---------------------------------------------------------------------------
// remove()
// marks the item as deleted in the bool array
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool CustomerHashTable::remove(int customerID)
{
	int key = hashCustomer(customerID);
	int i = 1;
	while (table[key] != NULL)
	{
		if (table[key]->getID() == customerID)
		{	
			bucketEmpty[key] = true;
			return true;
		}
		else 
		{
			key = (key + (i * i) % tableSize);
			i++;
		}
	}
	return false;
}

//---------------------------------------------------------------------------
// getLoad()
// gets the current loadfactor of the hash table
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
double CustomerHashTable::getLoad()
{
	loadFactor = this->size / this->tableSize;
	return loadFactor;
}
		//get method that retrieves the size of the current hashtable.
//---------------------------------------------------------------------------
// getTableSize()
// returns the size of the hash table
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
int CustomerHashTable::getTableSize()
{
	return tableSize;
}
//---------------------------------------------------------------------------
// searchCustomer()
// returns true if the customer of the corresponding ID exists
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool CustomerHashTable::searchCustomer(int customerID, Customer *&c)
{
	int key = hashCustomer(customerID);
	int i = 1;
	while (table[key] != NULL)
	{
		if (table[key]->getID() == customerID)
		{
			c = table[key];
			return true;
		}
		else
		{
			key = (key + (i * i) % tableSize);
			i++;
		}
	}
	return false;
}
//---------------------------------------------------------------------------
// hashCustomer()
// returns the key of the customer object given the customer ID
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
int CustomerHashTable::hashCustomer(int customerID)
{
	int tmp = customerID * 13 % tableSize;
	return tmp;
}
