/*
Andrew Mashhadi
ID: 905092387
PIC 10B
Programming Homework #7

Honesty Pledge:

I, Andrew Mashhadi, pledge that this is my own individual work,
which conforms to the guidelines of academic honesty as described
in the course syllabus.
*/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <cassert>


class BinarySearchTree;
class TreeIterator;

class TreeNode
{

private:
	int data;
	TreeNode* left;
	TreeNode* right;

public:
	/* Constructor with parameters for TreeNode class. This initializes the data to a value and the left and right 
	pointers to nullptr.
	@param d is the integer value that data will be set to.
	*/
	TreeNode(int d);

	/* This is the TreeNode member function that helps insert a new node into a BinarySearchTree object using 
	recursion. Called usually from a BinarySearchTree object, this function finds the proper location for a new TreeNode
	in the BinarySearchTree object (using the BinarySearchTree properties). It deletes the node if a node with the same
	data already exists.
	@param newNode is the newly created TreeNode that we want to insert into the BinarySearchTree object that called this 
	funciton from its own insert function.
	@return void
	*/
	void insert_node(TreeNode* newNode);

	friend class BinarySearchTree;
	friend class TreeIterator;

};

class BinarySearchTree
{

private:
	TreeNode* root;

public:
	/* Default constructor for BinarySearchTree class. This intializes the root to nullptr. */
	BinarySearchTree();

	/* Creates a new TreeNode with new data, then either inserts the first TreeNode into the tree or calls the 
	insert_node function to recursively find the correct location in the tree for the new TreeNode to be inserted.
	@param new_dat is the data that the newly created TreeNode will contain.
	@return void.
	*/
	void insert(int new_dat);

	/* This function properly erases (and therefore deletes) a TreeNode from this BinarySearchTree object without 
	altering the correct BinarySearchTree structure.
	@param r_dat is the data in the TreeNode that we want to erase (and delete) properly.
	@return void.
	*/
	void erase(int r_dat);

	/* This function returns the TreeIterator that represents the "first" TreeNode in this BinarySearchTree object. In 
	this case, the beginning of the TreeIterator should coresspond to the TreeNode with the lowest valued data.
	@return the TreeIterator with position set to the TreeNode with lowest valued data.
	*/
	TreeIterator begin() const;

	/* This function returns a TreeIterator that represents the "last" TreeNode in this BinarySearchTree. In this case 
	we represent the one after the last TreeNode of this BinarySearchTree as a TreeIterator with position set to the nullptr.
	@return TreeIterator with position set to nullptr. 
	*/
	TreeIterator end() const;

	/* This function will help the destructor perform the task of deleting all of the dynamically allocated TreeNodes
	associated with this BinarySearchTree by using recursion.
	@param nodeptr is a TreeNode pointer pointing to the root of this BinarySearchTree.
	@return void
	*/
	void destructor_helper(TreeNode*nodeptr);

	/* Destructor for BinarySearchTree class. Properly deletes all of the dynamically allocated TreeNodes by calling
	the destructor_helper with the root as the argument. That call will cause the BinarySearchTree object to be 
	properly destructed so we have no memory leaks.
	*/
	~BinarySearchTree();

	friend class TreeIterator;

};

class TreeIterator
{

private:
	TreeNode* position;
	const BinarySearchTree* container;

public:
	/* Overloading the prefix increment operator so when we increment a TreeIterator we will go to the TreeNode with
	the next highest valued data. Uses the properties of the BinarySearchTree object.
	@return a reference to this TreeIterator, with the updated position location (TreeNode with the next highest data).
	*/
	TreeIterator& operator++();

	/* Overloading the postfix increment operator so when we increment a TreeIterator we will go to the TreeNode with
	the next highest valued data. Uses the properties of the BinarySearchTree object.
	@param dummy variable to differentiate between this postfix increment operator from the prefix increment operator.
	@return TreeIterator that is a copy of the TreeIterator with the position before moving this position to the TreeNode
	with the next highest data.
	*/
	TreeIterator operator++(int dummy);

	/* Overloaded == operator that allows us to compare two TreeIterators.
	@param other_it is the other TreeIterator that we are comparing this TreeIterator to.
	@return true if this TreeIterator's position is the same as the other_it's position. False otherwise.
	*/
	bool operator==(const TreeIterator& other_it) const;

	/* Overloaded != operator that allows us to compare two TreeIterators.
	@param other_it is the other TreeIterator that we are comparing this TreeIterator to.
	@return true if this TreeIterator's position is not same as the other_it's position. False otherwise.
	*/
	bool operator!=(const TreeIterator& other_it) const;

	/* Overloading dereferencing operator that will allow us to extract the data in the TreeNode that this TreeIterator's
	position is pointing to. 
	@return the integer valued data in the TreeNode that this TreeIterator is corresponding to.
	*/
	int operator*() const;

	friend class BinarySearchTree;
	
};

#endif