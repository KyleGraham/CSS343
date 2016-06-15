/******************* 
Kyle Graham
CSS 343 Winter 2016 
Project 2
Instructor: Dr. Parsons 
*******************/ 
#ifndef BINTREE_H
#define BINTREE_H
#include <string>
#include <iostream>
#include <fstream>
#include "NodeData.h"
using namespace std;

// simple class containing one string to use for testing
// not necessary to comment further

class BinTree {				// you add class/method comments and assumptions
	friend ostream & operator<<(ostream& out, const BinTree& a);
public:
	BinTree();							// constructor
	BinTree(BinTree& other);				// copy constructor
	~BinTree();								// destructor, calls makeEmpty	
	bool isEmpty() const;					// true if tree is empty, otherwise false
	void makeEmpty();				// make the tree empty so isEmpty returns true
	
	BinTree& operator=(BinTree& other);
	bool operator==(const BinTree& other) const;
	bool operator!=(const BinTree& other) const;
	bool insert(NodeData* tPtr);
	bool retrieve(const NodeData& item, NodeData*& found) const;
	void displaySideways() const;			// provided below, displays the tree sideways
	int getHeight (const NodeData& item) const;
	
	void bstreeToArray(NodeData* []);	//takes a BinTree object and puts it into an array
	void arrayToBSTree(NodeData* []);	//takes an array and puts it into a BinTree object
	
private:
	
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;				// right subtree pointer
		
	};
	Node* root;								// root of the tree

// utility functions
void inOrderHelper(Node* tPtr) const;
void sideways(Node* current, int) const;			// provided below, helper for displaySideways()
void deleteTree(Node*& tPtr);						// helper for make empty
void retrieveHelper(Node* tPtr, const NodeData& item, NodeData*& found) const;	//helper for retrieve function since it needs Node*
void copyTree(Node* ptr, Node*&newPtr);	//copies one tree to another
bool equalityHelper(Node* left, Node* right) const;	//helper function for == operator
int treeToArrayHelper(Node* cur, NodeData* treeArray[]); //helper function for tree to array
void arrayToTreeHelper(Node*& cur, NodeData* treeArray[], int smallest, int biggest); //helper function for array to tree
int heightHelper(Node* cur, int counter) const;	//helper function for getHeight
};

#endif