//Tyler Kowalczik, Kyle Graham 
#ifndef CustHistoryList_h
#define CustHistoryList_h

#include <iostream>
#include <string>
using namespace std;

class CustHistoryList
{
	
public:
    CustHistoryList();
    ~CustHistoryList();
    void insertFront(string movie);
	void insertBack(string movie);
    void printList();
	//void deleteList();
	void deleteList();
private:
    struct HistoryNode
    {
        HistoryNode *next;
        HistoryNode *prev;
        string movie;

		HistoryNode(string m) 
		{
			movie = m;
			this->next = NULL;
			this->prev = NULL;
		}
    };
    HistoryNode *head;
	HistoryNode *tail;
};

#endif