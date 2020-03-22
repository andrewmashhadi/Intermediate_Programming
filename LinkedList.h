/*
Andrew Mashhadi
ID: 905092387
PIC 10B
Programming Homework #6

Honesty Pledge:

I, Andrew Mashhadi, pledge that this is my own individual work,
which conforms to the guidelines of academic honesty as described
in the course syllabus.
*/


#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

class List;
class Iterator;

class Node
{
private:
	int data;					
	Node* next;
	Node* previous;

public:
	/* Constructs a node with a given int value.
	@param in_data is the data to store in this node
	*/
	Node(int in_data);

	friend class List;
	friend class Iterator;
};

class List
{
private:
	Node* head;
	Node* tail;

public:

	// Default constructor for List class. Constructs an empty list. 
	List();

	/* Copy constructor for List class. Used to create a new list with the same data values but with nodes at 
	diferent memory locations. This way, we do not modify the list that is being copied later on in the program.
	@param list is the List being copied from
	*/
	List(const List& list);

	/* Inserts a new node, with new data, in the front of the list. This new node is now the head node 
	of the list. 
	@param d is the new node's data
	@retun void
	*/
	void push_front(int d);

	/* Appends a new node, with new data, at the end of the list. This new node is now the tail node.
	@param d is the new node's data
	@return void
	*/
	void push_back(int d);

	/* Inserts a new node, with new data, into the list. We insert the new node infront of our Iterator
	parameter's position.
	@param it is the Iterator holding the position that we want our new node to be infront of
	@return an Iterator containing the position to the new node that we just inserted
	*/
	Iterator insert(const Iterator& it, int);

	/* Removes an element from the list. 
	@param it is the position we will remove 
	@return an Iterator "pointing" to the element after the erased node
	*/
	Iterator erase(const Iterator& it);

	/* Reverses the order and structure of this List's nodes.
	@return void
	*/
	void reverse();

	/* Sorts our list so that the nodes contain data in increasing order of integers. That is, the 
	head node has the lowest valued data and the tail node has the highest valued data.
	@return void
	*/
	void sort();

	/* Merges this List with another List passed in together to produce (and return) a third List 
	that conatins data from both Lists. That is, this function accepts another List object and merges
	the two Lists into one, alternating elements from each List.
	@param list is the other List we will merge this List with to create the new output List
	@return the merged List containing alternating elements from each List
	*/
	List merge(const List&);

	/* Gets the number of nodes with data from this List.
	@returns the number of nodes from this List
	*/
	int size() const;

	/* Gets the beginning position of this List and stores it into an Iterator.
	@return an Iterator "pointing" to the beginning of this list
	*/
	Iterator begin() const;

	/* Gets the one past the tail of the List position of this List (nullptr) and stores it into an Iterator.
	@return an Iterator pointing one past the end of the list 
	*/
	Iterator end() const;

	/* Destructor for List class. Once the List is destroyed, this will delete all the nodes 
	appropriately to make sure there is no memory leaks. 
	*/
	~List();

	friend class Iterator;
};

class Iterator
{
private:
	Node* position;
	const List* container;

public:

	// Default constructor for an Iterator with no connection  to a List. Sets member fields to nullptrs.
	Iterator();

	/* Overloads the prefix addition by one operator to move the Iterator to the next node.
	@return reference to the Iterator for the next node.
	*/
	Iterator& operator++();

	/* Overloads the postfix addition by one operator to move the Iterator to the next node.
	@param a dummy variable meant to differentiate the postfix operator overload from the prefix.
	@return a copy of the Iterator before moving the position up to the next node.
	*/
	Iterator operator++(int dummy);

	/* Overloads the prefix subtraction by one operator to move the Iterator to the previous node.
	@return reference to the Iterator for the previous node.
	*/
	Iterator& operator--();

	/* Overloads the postfix subtraction by one operator to move the Iterator to the previous node.
	@param a dummy variable meant to differentiate the postfix operator overload from the prefix.
	@return a copy of the Iterator before moving the position to the previous node.
	*/
	Iterator operator--(int dummy);

	/* Overloads the not equals to operator. Tells us if the positon of this Iterator is not the same as 
	the position of the parameter Iterator's position. 
	@return true if the positions of the two Iterators are not equal, false if they are. 
	*/
	bool operator!=(const Iterator& it) const;

	/* Overloads the not equals to operator. Tells us if the positon of this Iterator is the same as
	the position of the parameter Iterator's position.
	@return true if the positions of the two Iterators are equal, false if they are not.
	*/
	bool operator==(const Iterator&) const;

	/* Gets the data value of the node this Iterator is "pointing" to (the position Node's data).
	@return the data value of the node this Iterator is "pointing" to.
	*/
	int operator*() const;		

	/* We don't have a destructor for Iterator becasue we don't want to delete 
	what position and container point just because an Iterator is destroyed. 
	*/
	
	friend class List;
};

// NONMEMBER FUNCTION DECLARATON

/* Overloads the output stream operator so that we can easily display the List in the way shown
in the homework #6 sample run, without constantly using a loop. 
@param out the outout stream object we want to use to display each element of List. 
@param list is the List conaining all the elements we want to display.
@return a reference to the ostream object that was passed in by reference so we can have a chain 
of outputs to the stream.
*/
std::ostream& operator<<(std::ostream& out, List& list);		

/* Fills the parameter List with integer values in the same way shown in the sample output.
@param list is the List that the user will fill up with values
@return void
*/
void fill_list(List& list);

/* One by one, the function inserts integer values in user specified locations of the parameter List 
untill the user is done, as shown in the sample output.
@param list is the List that the user will insert values into
@return void
*/
void insert_list(List&);


#endif
