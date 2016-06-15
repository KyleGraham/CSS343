//Tyler Kowalczik, Kyle Graham 
#include "Customer.h"
//---------------------------------------------------------------------------
// Customer()
// default constructor for customer objects
// Preconditions: NONE
// Postconditions: customer object created
// ---------------------------------------------------------------------------
Customer::Customer()
{
	customerID = 0;
	firstName = "";
	lastName = "";
}
//---------------------------------------------------------------------------
// Customer()
// constructor for customer objects
// Preconditions: NONE
// Postconditions: customer object created
// ---------------------------------------------------------------------------
Customer::Customer(int ID, string first, string last)
{
	this->customerID = ID;
	this->firstName = first;
	this->lastName = last;
	
}
//---------------------------------------------------------------------------
// ~Customer()
// destructor for customer objects
// Preconditions: customer object exists
// Postconditions: customer object deleted
// ---------------------------------------------------------------------------
Customer::~Customer()
{
	clear();
	delete this;
}
//---------------------------------------------------------------------------
// getID()
// returns the id number of a customer
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
int Customer::getID()
{
	return customerID;
}
//---------------------------------------------------------------------------
// getWholeName()
// returns the whole name of a customer
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
string Customer::getWholeName()
{
	string temp = "";
	temp.append(firstName);
	temp.append(", ");
	temp.append(lastName);
	return temp;
}
//---------------------------------------------------------------------------
// getFirstName()
// returns the first name of a customer
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
string Customer::getFirstName()
{
	return firstName;
}
//---------------------------------------------------------------------------
// getLastName()
// returns the last name of a customer
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
string Customer::getLastName()
{
	return lastName;
}
//---------------------------------------------------------------------------
// printHistory()
// prints the customers history from the linked list
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
void Customer::printHistory()
{
	cout << "------------TRANSACTION HISTORY------------" << endl;
	cout << "Customer ID: " << this->customerID << endl;
	cout << "Customer name: " << this->lastName << ", " << this->firstName << endl;
	custHistory.printList();
	
}
//---------------------------------------------------------------------------
// printCustomer()
// prints the customers id and name
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
void Customer::printCustomer()
{
	cout << customerID << " " << getWholeName() << endl;
}
//---------------------------------------------------------------------------
// operator==()
// returns true if two customers are the same
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
bool Customer::operator==(const Customer & c) const
{

	if (this->customerID != c.customerID)
				return false;
			else
				return true;
}
//---------------------------------------------------------------------------
// addHistory()
// adds a string to the history of the customer
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
void Customer::addHistory(string item)
{
	custHistory.insertFront(item);
}
//---------------------------------------------------------------------------
// clear()
// destructor helper for customer objects
// Preconditions: customer object exists
// Postconditions: customer object emptied
// ---------------------------------------------------------------------------
void Customer::clear()
{
	this->custHistory.deleteList();
	this->customerID = 0;
	this->size = 0;
	this->firstName = "";
	this ->lastName = "";
}

