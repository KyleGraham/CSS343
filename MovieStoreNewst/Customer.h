
#ifndef _MY_CUSTOMER
#define _MY_CUSTOMER

#include <iostream>
#include <string>
#include <vector>
#include "CustHistoryList.h"
// ---------------------- Customer.h ------------------------- 
// Tyler Kowalczik, Kyle Graham  
// CSS343
// Creation Date: 2/29/2016
// Date of Last Modification: 2/29/2016
// ---------------------------------------------------------------- 
// Purpose: Abstract class for customers. Stores a customer's data
//	and their history of transactions.
// ----------------------------------------------------------------
// Special Algorithms:
// - Hashing functions. This class is derived from hashable class
// ----------------------------------------------------------------
// Assumptions: 
//	- Users will not need to search transaction history.
//	- Transaction history is displayed in chronological order.
//	- Customer class won't require extension.
// ----------------------------------------------------------------
using namespace std;
class Customer {
public:
	//default constructor
	Customer();
	Customer(int ID, string first, string last);
	//default destructor
	~Customer();
	//get customer's unique id number
	int getID();
	//Ways to retrieve customer name
	string getWholeName();
	string getFirstName();
	string getLastName();
	//prints all transactions of a customer
	void printHistory();
	void printCustomer();
	void addHistory(string item);
	bool operator==(const Customer &c) const;
	void clear();
private:
	int customerID;		//customer unique id
	int size;			//size of vector
	//int transactions;
	string firstName;	
	string lastName; 
	//string custHistory[];
	CustHistoryList custHistory;
};

#endif