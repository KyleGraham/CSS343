//Tyler Kowalczik, Kyle Graham 
#include "CustHistoryList.h"
//---------------------------------------------------------------------------
// CustHistoryList()
// creates a custhistorylist object
// Preconditions: NONE
// Postconditions: created custhistorylist object
// ---------------------------------------------------------------------------
CustHistoryList::CustHistoryList()
{
	this->head = NULL;
	this->tail = NULL;
}
//---------------------------------------------------------------------------
// ~CustHistoryList()
// deletes a custhistorylist object
// Preconditions: full custhistorylist object
// Postconditions: deleted custhistorylist object
// ---------------------------------------------------------------------------
CustHistoryList::~CustHistoryList() 
{
	this->deleteList();
	
}
//---------------------------------------------------------------------------
// insertFront()
// inserts a string object into the front of the linked list
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
void CustHistoryList::insertFront(string movie)
{
	HistoryNode *h = new HistoryNode(movie);

	if (head != NULL)
		head->prev = h;

	h->next = head;
	h->prev = NULL;
		
	head = h;
}
//---------------------------------------------------------------------------
// insertBack()
// inserts a string object into the back of the linked list
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
void CustHistoryList::insertBack(string movie)
{
	HistoryNode *h = new HistoryNode(movie);

	if (tail != NULL)
		tail->next = h;

	h->prev = tail;
	h->next = NULL;
	tail = h;
}
//---------------------------------------------------------------------------
// printList()
// prints out the contents of the custhistorylist
// Preconditions: NONE
// Postconditions: NONE
// ---------------------------------------------------------------------------
void CustHistoryList::printList()
{
	HistoryNode *srch = head;

	if (srch == NULL)
		return;
	else
		cout << srch->movie << endl;

	while (head->next != NULL)
	{
		head = head->next;
		cout << head->movie << endl;
	}
}
//---------------------------------------------------------------------------
// deleteList()
// destructor helper for custhistorylist objects
// Preconditions: full list
// Postconditions: empty and deleted list
// ---------------------------------------------------------------------------
void CustHistoryList::deleteList()
{
	if (head == NULL)
		return;
	else
	{
		while (head->next != NULL)
		{
			head = head->next;
			delete head->prev;
		}
		delete head;
	}
}
