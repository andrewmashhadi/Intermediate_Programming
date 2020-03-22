#include "BinarySearchTree.h"


TreeNode::TreeNode(int d) : data(d), left(nullptr), right(nullptr) { }

void TreeNode::insert_node(TreeNode* newNode)		
{
	/* If the new TreeNode's data is less than this TreeNode's data, move to the left child.
	Otherwise if the new TreeNode's data is greater than this TreeNode's data, move to the right child.
	Otherwise the new TreeNode's data is exactly the same as the data from a previously inserted TreeNode.
	So we delete the new TreeNode.
	*/
	if (newNode->data < data)
	{
		if (this->left == nullptr)
			left = newNode;
		else
			left->insert_node(newNode);
	}
	else if (newNode->data > data)
	{
		if (this->right == nullptr)
			right = newNode;
		else
			right->insert_node(newNode);
	}
	else
	{
		delete newNode;
	}

}

BinarySearchTree::BinarySearchTree() : root(nullptr) { }

void BinarySearchTree::insert(int new_dat)
{
	TreeNode* newNode = new TreeNode(new_dat);
	/* If the BinarySearchTree is empty, set the root to point to the first new TreeNode.
	Otherwise call insert_node function to find the new TreeNode's place in this BinarySearchTree.
	*/
	if (root == nullptr)
		root = newNode;
	else
		root->insert_node(newNode);
}

void BinarySearchTree::erase(int r_dat)
{
	TreeNode* remove = root;
	TreeNode* parent = nullptr;

	// While the remove pointer has not reached a nullptr in its search for the TreeNode with r_data.
	while (remove != nullptr)
	{
		/* If the remove TreeNode data is less than r_data, move to the right child.
		Otherwise if the remove TreeNode data is greater than the r_data, move to the left child.
		Otherwise the new TreeNode's data is exactly the same as the data from a previously inserted TreeNode.
		So we break from our while loop becasue remove and parent are at the proper location.
		*/
		if (remove->data < r_dat)
		{
			parent = remove;
			remove = remove->right;
		}
		else if (remove->data > r_dat)
		{
			parent = remove;
			remove = remove->left;
		}
		else
		{
			break;
		}
	}

	// If none of this BinarySearchTree's TreeNodes conatain r_data, we don't erase anything. So we return.
	if (remove == nullptr)
		return;

	// If remove only has a single child.
	if (remove->right == nullptr || remove->left == nullptr)
	{
		TreeNode* newChild = nullptr;

		// If remove only has a right child, set newChild to the right child. Otherwise set newChild to the left child.
		if (remove->left == nullptr)
			newChild = remove->right;
		else
			newChild = remove->left;

		/* If we are erasing the root TreeNode, set the root to the only child of remove.
		Otherwise if remove is the left child of parent, set remove's only child as the new left child of parent.
		Otherwise remove is the right child of parent, so set remove's only child as the new right child of parent.
		*/
		if (parent == nullptr)
			root = newChild;
		else if (parent->left == remove)
			parent->left = newChild;
		else
			parent->right = newChild;

		delete remove;
		remove = nullptr;
		return;
	}

	TreeNode* replace_parent = remove;
	TreeNode* replace_del = remove->right;

	// While we are not at the TreeNode with the next highest valued data from remove's data, keep moving to the left child.
	while (replace_del->left != nullptr)
	{
		replace_parent = replace_del;
		replace_del = replace_del->left;
	}

	remove->data = replace_del->data;

	/* If the TreeNode with the next highest valued data was immediately to the right of remove, set the orginal remove
	TreeNode's right child equal to the right child of the new TreeNode we are going to delete. Otherwise, set the 
	replacement parent TreeNode's left child equal to the right child of the new TreeNode we are going to delete.
	*/
	if (replace_parent == remove)
		replace_parent->right = replace_del->right;
	else
		replace_parent->left = replace_del->right;

	delete replace_del;
	replace_del = nullptr;
}

TreeIterator BinarySearchTree::begin() const
{
	TreeIterator temp;
	temp.container = this;
	TreeNode* nodeptr = root;

	// If this BinarySearchTree is empty, set the beginning TreeIterator position to nullptr.
	if (root == nullptr)
	{
		temp.position = nullptr;
		return temp;
	}

	// While the nodeptr is not at the TreeNode with the lowest valued data.
	while (nodeptr->left != nullptr)
		nodeptr = nodeptr->left;

	temp.position = nodeptr;
	return temp;
}

TreeIterator BinarySearchTree::end() const
{
	TreeIterator temp;
	temp.position = nullptr;
	temp.container = this;
	return temp;
}

void BinarySearchTree::destructor_helper(TreeNode* nodeptr)
{
	/* If the nodeptr is not pointing to the nullptr (means the BinarySearchTree is not empty), so we have more 
	TreeNodes to delete. 
	*/ 
	if (nodeptr != nullptr)
	{
		// If the left child of nodeptr is not pointing to the nullptr, we destroy/delete the left subtree.
		if (nodeptr->left != nullptr)
			destructor_helper(nodeptr->left);

		// If the right child of nodeptr is not pointing to the nullptr, we destroy/delete the right subtree.
		if (nodeptr->right != nullptr)
			destructor_helper(nodeptr->right);

		delete nodeptr;
		nodeptr = nullptr;										
	}

}

BinarySearchTree::~BinarySearchTree()		
{
	destructor_helper(root);
}
											
TreeIterator& TreeIterator::operator++()	// Could use parent node in TreeNode class, and could navigate using the actual data values too.
{														
	assert(position != nullptr);						
	TreeNode* nodeptr = container->root;
	TreeNode* last_left = container->root;
	TreeNode* last_left_parent = nullptr;

	// While loop will run until a break statement is called inside.
	while (true)
	{
		/* If the data in the TreeNode that nodeptr points to is less than the data in the TreeNode that position 
		points to we set the nodeptr to point to its right child.
		Otherwise if the data in the TreeNode that nodeptr points to is more than the data in the TreeNode that position 
		points to we set the nodeptr to point to its left child, while updating the latest left movement down the 
		BinarySearchTree to store in last_left_parent and last_left. 
		Otherwise nodeptr has reached the position TreeNode, so we break.
		*/
		if (nodeptr->data < position->data)
		{
			nodeptr = nodeptr->right;
		}
		else if (nodeptr->data > position->data)
		{
			last_left_parent = nodeptr;
			last_left = nodeptr->left;
			nodeptr = nodeptr->left;
		}
		else
		{
			break;
		}
	}

	/* If the right child of the TreeNode that this TreeIterator is at is not the nullptr, we move to the right child
	and then all the way to the left most TreeNode (if possible). Otherwise, position is set to the TreeNode that is
	the closest right ancestor (could be nullptr if only left ancestors). That is, the parent of TreeNode that was found
	from the last left we took navigating down the BinarySearchTree to find position's TreeNode.
	*/
	if (nodeptr->right != nullptr)
	{
		nodeptr = nodeptr->right;

		/* Move all the way to the TreeNode with the lowest valued data greater than the data in the TreeNode
		that position points to. That is, the left most TreeNode from the right child of the TreeNode that position points to. 
		*/
		while (nodeptr->left != nullptr)
			nodeptr = nodeptr->left;

		position = nodeptr;
	}
	else
	{
		position = last_left_parent;
	}

	return *this;
}

TreeIterator TreeIterator::operator++(int dummy)
{
	TreeIterator temp = *this;
	++(*this);
	return temp;
}								

bool TreeIterator::operator==(const TreeIterator& other_it) const
{
	return position == other_it.position;
}

bool TreeIterator::operator!=(const TreeIterator& other_it) const
{
	return position != other_it.position;
}

int TreeIterator::operator*() const
{
	assert(position != nullptr);
	return position->data;
}