// ---------------------- BinTree.cpp ---------------------------------------
//
// Kyle Graham
// CSS 343B
// 1/20/16
// Last modified : 2/1/16
// --------------------------------------------------------------------------
// Purpose - Functions for BinTree class
// Assumptions - getHeight finds the node first, then searched for how far 
// from the bottom it is. 
// Assignment 2
// --------------------------------------------------------------------------
#include "BinTree.h"
//------------------------- BinTree() ---------------------------------------
// Creates a binTree object when no paramaters are given.
// Default constructor for BinTree objects
// Preconditions: NONE
// Postconditions: BinTree created.
// --------------------------------------------------------------------------
BinTree::BinTree():root(NULL)
{
}
//------------------------- ~BinTree() --------------------------------------
// Deletes a BinTree object.
// Destructor for BinTree objects.
// Preconditions: BinTree object exists
// Postconditions: BinTree deleted.
// --------------------------------------------------------------------------
BinTree::~BinTree()
{
	deleteTree(root);	//deletes the tree
}
//------------------------- BinTree(BinTree&) -------------------------------
// Creates a new BinTree object copy of the given BinTree parameter
// Copy constructor for BinTree objects
// Preconditions: NONE
// Postconditions: BinTree copy of parameter created.
// --------------------------------------------------------------------------
BinTree::BinTree(BinTree &other)
{
	root = NULL;	//initializes root
	
	if(!(other.isEmpty()))	//copies other to this
		copyTree(other.root, this->root);
}
//------------------------- operator= ---------------------------------------
// Copies the given BinTree object to a different BinTree object
// Assignment operator for BinTree objects
// Preconditions: BinTree object is already initialized.
// Postconditions: BinTree a is copied to *this.
// --------------------------------------------------------------------------
BinTree& BinTree::operator=(BinTree &other)
{
	if(*this != other)
	{
		this->makeEmpty();	//empties the tree for copying
		
		copyTree(other.root, this->root);	//copies other to this
	}
	return *this;

}
//------------------------- getHeight ----------------------------------------
// Finds the height of a given node.
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------
int BinTree::getHeight(const NodeData &item) const
{
	bool success = false;
	int counter = 1;
	Node* tPtr = root;	//starts search at root

	while(success == false)	//loops until the value is found
	{
		if(tPtr == NULL)	//not found, returns 0
			return 0;
		else if(item == *tPtr->data)		//found
		{
			success = true;
			
			counter = heightHelper(tPtr, 1); //finds how far from the bottom it is
		}
		else if(item < *tPtr->data)	//less than, go left
		{
			tPtr = tPtr->left;
		}
		else					//greater than, go right
		{
			tPtr = tPtr->right;
		}
	}
return counter;
}
//------------------------- heightHelper ------------------------------------
// Takes in the position of a node.
// finds how far from the bottom the found node is.
// Preconditions: Node found with getHeight
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------
int BinTree::heightHelper(Node* cur, int counter) const
{
	
	if(cur->right == NULL && cur->left == NULL)
	{
		return counter;	//at leaf, return
	}

	if(cur->right != NULL && cur->left != NULL)
	{
		counter++;	//checks how far from the bottom when there is a right and 
		int leftMax = heightHelper(cur->left, counter);	//left node recursively	
		int rightMax = heightHelper(cur->right, counter);
		return max(leftMax, rightMax);	//returns whichever path is greater.
		
	}
	else if(cur->left != NULL && cur->right == NULL)
	{
		cur = cur->left;	//only one path to take, moves left and calls
		counter++;			//the helper function recursively
		heightHelper(cur, counter);
	}
	else if(cur->left == NULL && cur->right != NULL)
	{
		cur = cur->right;	//only one path to take, moves right and calls
		counter++;			//the helper function recursively
		heightHelper(cur, counter);
	}
	
}
//------------------------- isEmpty -----------------------------------------
// Returns true if the tree is empty.
// Returns false if otherwise.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------
bool BinTree::isEmpty() const
{
	if(root == NULL)	//checks if the root is empty, cant have a tree with 
		return true;	//no root
	else
		return false;
}
//------------------------- makeEmpty ---------------------------------------
// Empties the BinTre object.
// Calls deleteTree to empty the BinTree object
// Preconditions: BinTree not empty.
// Postconditions: BinTree emptied.
// --------------------------------------------------------------------------
void BinTree::makeEmpty()
{
	deleteTree(root);	//calls helper function
}
//------------------------- deleteTree ---------------------------------------
// Deletes a BinTree object recursively.
// Post order delete.
// Preconditions: NONE
// Postconditions: BinTree emptied.
// --------------------------------------------------------------------------
void BinTree::deleteTree(Node *& tPtr)
{
	if(tPtr != NULL)
		{
			deleteTree(tPtr->left);		//recursively calls delete post order
			deleteTree(tPtr->right);	
			if(tPtr->data != NULL)
			{
				delete tPtr->data;		//if there's data, delete it
				tPtr->data = NULL;
			}
			delete tPtr;
			tPtr = NULL;
		}
}
//------------------------- retrieve ------------------------------------------
// Returns true if the node is found, false if otherwise.
// Uses retrieveHelper to find if the node is present.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------
bool BinTree::retrieve(const NodeData & item, NodeData*& found) const
{
	retrieveHelper(root, item, found);
	if(found == NULL)		//not found, variable not changed
		return false;
	else                    //found successfully
		return true;
}
//------------------------- retrieveHelper -------------------------------------
// Searches for the given node iteratively.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------
void BinTree::retrieveHelper(Node* tPtr, const NodeData& item, NodeData*& found)
	const
{
	bool success = false;
	while(success == false)
	{
		if(tPtr == NULL)		//data not found in tree, hit null node
		{
			found = NULL;		//exits with a null found
			success = true;	//exit while loop
		}
		else if(*tPtr->data == item)	//data found
		{
			found = tPtr->data;
			success = true;
		}
		else if(*tPtr->data < item)		//item is larger, move right
		{
			tPtr = tPtr->right;
		}
		else                            //item is smaller, move left
		{
			tPtr = tPtr->left;
		}
	}
}
//------------------------- insert ---------------------------------------------
// iteratively inserts a new node with input data
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------
bool BinTree::insert(NodeData* input)
{
 
   if (isEmpty()) //empty tree, creates node and inserts at root
   {
	  Node* ptr = new Node;    
      ptr->data = input; 
      input = NULL; 
	  ptr->left = ptr->right = NULL;
      root = ptr; 
	  ptr = NULL;
	  delete ptr;
   }
   else	//tree not empty, looks for a leaf
   {
	  Node* ptr = new Node;    
	  ptr->data = input; 
	  input = NULL; 
	  ptr->left = ptr->right = NULL;
      Node* cur = root;
      bool success = false;
      while (success == false) 
      {
         if (*ptr->data == *cur->data) //Duplicate found, dont allow insert
         {	
            delete ptr; //Handle duplicate properly
            ptr = NULL;
			cur = NULL;
            return false;
         }
         else if (*ptr->data < *cur->data)	//smaller
         {
            if (cur->left == NULL)				// at leaf, insert left
            {            
               cur->left = ptr;
               success = true;
			   ptr = NULL;
			   delete ptr;
            }
            else
			{
               cur = cur->left;					// one step left
			   
			}
         }
         else {                                //bigger
            if (cur->right == NULL) 
            {								   // at leaf, insert right
               cur->right = ptr;
               success = true;
			   ptr = NULL;
			   delete ptr;
            }
            else                              //not at leaf, moves right
			{
               cur = cur->right;              // one step right
			}
         }
      }
	  delete ptr;	//deletes the comparison pointer
   }
	
   return true;
}

//------------------------- copyTree ---------------------------------------
// Recursively copies one BinTree to another in modifed post order.
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------
void BinTree::copyTree(Node* ptr, Node*&newPtr) 
{
	if(ptr != NULL)	//base case, node not empty, copies
	{

		newPtr = new Node;					
		NodeData *temp = new NodeData(*ptr->data);
		newPtr->data = temp;

		copyTree(ptr->left, newPtr->left);		//moves left to copy left node		
		copyTree(ptr->right, newPtr->right);	//moves right to copy right node 
					
	}
	else    //at leaf
		newPtr = NULL;
}
//------------------------- operator<< --------------------------------------
// Output function for BinTree objects.
// Prints out BinTree objects using inOrderHelper function.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.\
// --------------------------------------------------------------------------
ostream & operator<<(ostream & out, const BinTree & a)
{
	a.inOrderHelper(a.root);	//puts the tree in order to be printed out
	out << endl;
	return out;
}
//------------------------- inOrderHelper -----------------------------------
// Helps output BinTree objects by putting them in order recursively.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------
void BinTree::inOrderHelper(Node *tPtr) const
{
	if(tPtr !=	NULL)
	{
		inOrderHelper(tPtr->left);	//prints out the nodes in order
		cout << *tPtr->data << " ";
		inOrderHelper(tPtr->right);
	}
}
//------------------------- operator== -------------------------------------
// Checks if two BinTree objects are equal using the equalityHelper function
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------
bool BinTree::operator==(const BinTree &a) const
{
	if(a.root == NULL && root == NULL)	//if both are empty, then equal
		return true;
	else
		return equalityHelper(root, a.root);//helper function checks if the 
}												//BinTree objects are equal
//------------------------- operator!= --------------------------------------
// Checks if two BinTree objects are not equal using the == operator.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree &a) const
{
	if(*this == a)	//if they're equal, return false
		return false;
	else
		return true;
}
//------------------------- equalityHelper ----------------------------------
// Displays a binary tree as though you are viewing it from the side.
// Helps == operator check for equality recursively.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------
bool BinTree::equalityHelper(Node* left, Node* right) const
{
	if(right == NULL || left == NULL)//if one null and other not, not equal
		return false;
	if((*right->data == *left->data) && (right != NULL && left != NULL))
		return true;	//both same, return true
	return((*right->data == *left->data) && 
		equalityHelper(left->left, right->left)
		&& equalityHelper(left->right, right->right));//checks left and right
}
//------------------------- bstreeToArray -----------------------------------
// Takes a BinTree object and puts it into an array.
// Uses treeToArrayHelper to put the tree into the array.
// Preconditions: NONE
// Postconditions: BinTree is deleted.
// --------------------------------------------------------------------------
void BinTree::bstreeToArray(NodeData* treeArray[])
{
	treeToArrayHelper(root, treeArray);	//calls helper function
	deleteTree(root);	//deletes the empty tree
}
//------------------------- treeToArrayHelper -------------------------------
// Moves all the nodes from a BinTree object to an array.
// Moves all the nodes in post order.
// Preconditions: NONE
// Postconditions: BinTree filled with NULLs.
// --------------------------------------------------------------------------
int BinTree::treeToArrayHelper(Node* cur, NodeData* treeArray[])
{
	if(cur == NULL)
		return 0;
	int left = treeToArrayHelper(cur->left, treeArray);	//goes to left leaf
	NodeData *temp;										//for post order
	temp = cur->data;
	cur->data = NULL;
	*(treeArray + left) = temp;
	temp = NULL;	//deletes temp and disconnects
	delete temp;
	int right = treeToArrayHelper(cur->right, treeArray + left + 1);
	int answer = left + right + 1;
	return answer;	//return position of array
}
//------------------------- arrayToBSTree -----------------------------------
// Finds how many nodes the tree will have, and calls the helper
// function to fill the tree 
// Preconditions: BinTree empty
// Postconditions: BinTree filled up with array values.
// --------------------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData* treeArray[])
{
	int smallest = 0;
	int biggest = 0;
	for(int i = 0; i < 100; i++)	//Goes through the array, ignores nulls, 
 	{                                   //increases counter for values
		if(treeArray[i] == NULL)		//determines how big the tree is
			; 
		else
			biggest++;

	}
	root = NULL;
	if(isEmpty())//doesnt delete tree if already empty, just calls helper
	{
		
		arrayToTreeHelper(this->root, treeArray, smallest, biggest-1);

	}
	else        //not empty, deletes tree then calls helper
	{
		deleteTree(root);
		arrayToTreeHelper(this->root, treeArray, smallest, biggest-1);
	}
}
//------------------------- displaySideways ---------------------------------
// Puts the array values back into the BinTree.
// Preconditions: BinTree empty
// Postconditions: BinTree filled with array values.
// --------------------------------------------------------------------------
void BinTree::arrayToTreeHelper(Node*& cur, NodeData* treeArray[], 
								int smallest, int biggest)
{
	if(smallest > biggest)	//empty array, creates empty tree
		cur = NULL;
	else
	{
		int index = (biggest+smallest)/2;	//index of the root
		NodeData* temp;
		temp = treeArray[index];
		treeArray[index] = NULL;
		bool success = insert(temp);
		if(!success)
			delete temp; //if not inserted successfully, deletes pointer.
		//checks right half of the array.
		arrayToTreeHelper(cur->right, treeArray, index + 1, biggest);
		//checks left half of the array
		arrayToTreeHelper(cur->left, treeArray, smallest, index - 1);
		
	}
}
//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}
//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
// --------------------------------------------------------------------------
void BinTree::displaySideways() const {
	sideways(root, 0);
}
