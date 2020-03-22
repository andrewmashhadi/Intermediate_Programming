#include "BinarySearchTree.h"


int main()
{

	BinarySearchTree bst;
	bst.insert(3); bst.insert(2); bst.insert(11);
	bst.insert(13); bst.insert(5); bst.insert(17); bst.insert(17);
	std::cout << "Your tree consists of : ";

	// Displays contents of the BinarySearchTree object, bst.
	for (auto x : bst) std::cout << x << ",";
	std::cout << std::endl;
	bst.erase(6);
	bst.erase(11);
	std::cout << "Tree now consists of : ";

	// Display contents of the BinarySearchTree object, bst.
	for (auto x : bst) std::cout << x << ",";
	std::cout << std::endl;
	TreeIterator start = bst.begin();
	TreeIterator stop = bst.end();
	std::cout << "Checking initial value: ";

	// If the start TreeIterator is at a diffent position than the end TreeIterator.
	if (start != stop) std::cout << *start++ << std::endl;
	
	return 0;
}