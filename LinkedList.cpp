#include "LinkedList.h"
#include <cassert>
#include <string>


Node::Node(int in_data) : data(in_data), next(nullptr), previous(nullptr) { }

List::List() : head(nullptr), tail(nullptr) { }

List::List(const List& list)
{	
	/* Push new nodes with the same data values as in the nodes from the List object we are copying from. 
	Uses an iterator to go through list.
	*/
	for (Iterator it = list.begin(); it != list.end(); ++it)
	{
		push_back(*it);
	}
}

void List::push_front(int d)
{
	Node* newNode = new Node(d);
	/* If the list is empty, point head and tail to the first node inserted in this list. Otherwise, attach
	the new node onto the front of the list and adjust the head pointer.
	*/
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->previous = newNode;
		head = newNode;
	}
}

void List::push_back(int d)
{
	Node* newNode = new Node(d);
	/* If the list is empty, point head and tail to the first node pushed to this list. Otherwise, attach
	the new node onto the end of the List and adjust the head pointer.
	*/
	if (tail == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->previous = tail;
		tail = newNode;
	}
}

Iterator List::insert(const Iterator& it, int d)
{
	/* If the position of the iterator is one past the end, we call push_back function and return an 
	Iterator "pointing" to the tail node.
	*/
	if (it.position == nullptr)
	{
		push_back(d);
		Iterator new_it;
		new_it.position = tail;
		new_it.container = this;
		return it;
	}

	Node* newNode = new Node(d);
	Node* nodeptr = it.position;
	Node* prevptr = nodeptr->previous;
	newNode->next = nodeptr;
	nodeptr->previous = newNode;
	newNode->previous = prevptr;

	/* If the new node is to be the first node in our list, set the head to "point" to it and return Iterator
	"pointing" to the head
	*/
	if (prevptr == nullptr)
	{
		head = newNode;
		return begin();
	}

	prevptr->next = newNode;	
	Iterator new_it;
	new_it.position = newNode;
	new_it.container = this;
	return new_it;

}
// Could have also passed in reference and returned the updated Iterator. This way, there is no longer an Iterator pointing to garbage data.
Iterator List::erase(const Iterator& it)	
{
	assert(it.position != nullptr);
	Node* remove = it.position;
	Node* before = remove->previous;
	Node* after = remove->next;

	/* If we are removing the head node, set the head to the next element. Otherwise, connect
	the node before remove to the node after it.
	*/
	if (remove == head)
		head = after;
	else
		before->next = after;
	/* If we are removing the tail node, set the tail to the previous element. Otherwise, connect 
	the node after remove to the node before it.
	*/
	if (remove == tail)
		tail = before;
	else
		after->previous = before;

	delete remove;
	Iterator iter;
	iter.position = after;
	iter.container = this;
	return iter;
}

// We could have simply changed the data within the nodes. However, we changed the structure of the node instead.
void List::reverse()			
{
	// If the list is empty, return.
	if (head == nullptr)
		return;

	Node* temp = nullptr;
	Node* nodeptr = head;

	// Loop through all of the lists nodes.
	while (nodeptr != nullptr)
	{
		temp = nodeptr;
		nodeptr = nodeptr->next;

		temp->next = temp->previous;
		temp->previous = nodeptr;
	}
	
	temp = head;
	head = tail;
	tail = temp;
}

/* We could make this sort function const, since we are just changing the data in the object that our 
member field points to and not changing this list's actual member fields (because they are pointers), 
but we choose not to so that this sort function is not misleading.
*/
void List::sort()			
{	
	
	Node* nodeptr_1 = head;
	// Loop through all of this List's nodes.
	while (nodeptr_1 != nullptr)
	{
		int lowest = nodeptr_1->data;
		Node* lowestnode = nodeptr_1;
		Node* nodeptr_2 = nodeptr_1;
		/* Loop through the rest of the List's nodes. From the node that nodeptr_2 points to, to the last 
		node in the List. 
		*/
		while (nodeptr_2 != nullptr)
		{
			/* If the data in the node that nodeptr_2 points to is less than the lowest element so far,
			make it the lowest.
			*/
			if (nodeptr_2->data < lowest)
			{
				lowest = nodeptr_2->data;
				lowestnode = nodeptr_2;
			}
			nodeptr_2 = nodeptr_2->next;
		}
		int temp = nodeptr_1->data;		
		nodeptr_1->data = lowest;
		lowestnode->data = temp;
		nodeptr_1 = nodeptr_1->next;
	}

	// These are alternate sorting algorithms that sort the structure of the nodes, not the data in the nodes.
	
	/*
	Iterator i = begin();
	while (i != end())
	{
		Iterator j = i;
		int smallest = *j;
		Iterator smallest_it = j;
		while (j != end())
		{
			if (*j < smallest)
			{
				smallest = *j;
				smallest_it = j;
			}
			j++;
		}
		if (i != smallest_it)
		{
			this->insert(i, smallest);
			this->erase(smallest_it);
		}
		else
		{
			i++;
		}
	}
	*/
	/*
	Node* nodeptr_1 = head;
	while (nodeptr_1 != nullptr)
	{
		int lowest = nodeptr_1->data;
		Node* lowestnode = nodeptr_1;
		Node* nodeptr_2 = nodeptr_1;
		while (nodeptr_2 != nullptr)
		{
			if (nodeptr_2->data < lowest)
			{
				lowest = nodeptr_2->data;
				lowestnode = nodeptr_2;
			}
			nodeptr_2 = nodeptr_2->next;
		}
		if (lowestnode != nodeptr_1)
		{
			Node* behind_ln = lowestnode->previous;
			Node* infront_ln = lowestnode->next;
			Node* infront_np1 = nodeptr_1->next;
			Node* behind_np1 = nodeptr_1->previous;
			if (nodeptr_1 == head)
				head = lowestnode;
			else
				behind_np1->next = lowestnode;

			if (lowestnode != tail)
				infront_ln->previous = nodeptr_1;
			else
				tail = nodeptr_1;

			if (nodeptr_1->next == lowestnode)
			{
				lowestnode->next = nodeptr_1;
				lowestnode->previous = behind_np1;
				nodeptr_1->next = infront_ln;
				nodeptr_1->previous = lowestnode;

			}
			else
			{
				lowestnode->next = infront_np1;
				lowestnode->previous = behind_np1;
				infront_np1->previous = lowestnode;
				behind_ln->next = nodeptr_1;
				nodeptr_1->previous = behind_ln;
				nodeptr_1->next = infront_ln;
			}
			nodeptr_1 = lowestnode->next;
		}
		else
		{
			nodeptr_1 = nodeptr_1->next;
		}

	}
	*/

}

List List::merge(const List& list)	
{
	List m_list;
	Node* nodeptr = head;
	Node* l_nodeptr = list.head;
	size_t i = 1;
	// Loop until we reach the end of one of the two Lists.
	while (nodeptr != nullptr && l_nodeptr != nullptr)
	{
		/* If i is odd then we push the data value from the node that nodeptr points to into our new List.
		Otherwise, we push the data value from the node that l_nodeptr points to into our new List.
		*/
		if (i % 2)
		{
			m_list.push_back(nodeptr->data);
			nodeptr = nodeptr->next;
		}
		else
		{
			m_list.push_back(l_nodeptr->data);
			l_nodeptr = l_nodeptr->next;
		}
		i++;
	}

	// Notice only one of these while loops will be used

	/* If the nodeptr is not pointing to the end of this List, we copy the rest of the values into
	the new List.
	*/
	while (nodeptr != nullptr)
	{
		m_list.push_back(nodeptr->data);
		nodeptr = nodeptr->next;
	}

	/* If the l_nodeptr is not pointing to the end of this List, we copy the rest of the values into
	the new List.
	*/
	while (l_nodeptr != nullptr)
	{
		m_list.push_back(l_nodeptr->data);
		l_nodeptr = l_nodeptr->next;
	}
	return m_list;
}
/* Alternate Merge function that merges with another. This changes this list and does NOT 
return a new list, instead it returns void.
*/
/*
void List::merge(const List& other)
{
	Iterator it_1 = begin();
	Iterator it_2 = other.begin();
	++it_1;
	while (it_1 != end())
	{
		if (it_2 != end())
		{
			insert(it_1, *it_2);
			++it_2;
		}
		++it_1;
	}

	while (it_2 != end())
	{
		push_back(*it_2);
		++it_2; 
	}


}
*/

int List::size() const
{
	Node* nodeptr = head;
	int i = 0;
	// Loops through all of the nodes in the list.
	while (nodeptr != nullptr)
	{
		i++;
		nodeptr = nodeptr->next;
	}
	return i;

}

Iterator List::begin() const
{
	Iterator it;
	it.position = head;
	/* 
	We can point a pointer to const to an object that can change (non-const), we just cannot
	make changes to the object through the pointer to const.
	*/
	it.container = this;				
	return it;
}

Iterator List::end() const
{
	Iterator it;
	it.position = nullptr;
	/*
	We can point a pointer to const to an object that can change (non-const), we just cannot
	make changes to the object through the pointer to const.
	*/
	it.container = this;
	return it;
}

List::~List()
{
	Node* nodeptr = head;
	// Loops through all the nodes in the list, used here to delete all of them along the way.
	while (nodeptr != nullptr)
	{
		Node* kill_node = nodeptr;
		nodeptr = nodeptr->next;
		delete kill_node;
	}
}

Iterator::Iterator() : position(nullptr), container(nullptr) { }

Iterator& Iterator::operator++()
{
	assert(position != nullptr);				
	position = position->next;
	return *this;
}

Iterator Iterator::operator++(int dummy)
{
	assert(position != nullptr);				
	Iterator temp = *this;				
	position = position->next;
	return temp;
}

Iterator& Iterator::operator--()
{
	assert(position != container->head);		
	/* If we are one past the last node, we set the position to the tail of the corresponding container.
	Otherwise, we just set the position to the node before the node we are currently at.
	*/
	if (position == nullptr)
		position = container->tail;
	else
		position = position->previous;
	
	return *this;
	
}

Iterator Iterator::operator--(int dummy)
{
	assert(position != container->head);		
	Iterator temp = *this;				
	/* If we are one past the last node, we set the position to the tail of the corresponding container.
	Otherwise, we just set the position to the node before the node we are currently at.
	*/
	if (position == nullptr)
		position = container->tail;
	else
		position = position->previous;
	return temp;
}

bool Iterator::operator!=(const Iterator& it) const
{
	return position != it.position;
}

bool Iterator::operator==(const Iterator& it) const
{
	return position == it.position;
}

int Iterator::operator*() const
{												
	assert(position != nullptr);
	return position->data;				
}

// NONMEMBER FUNCTION DEFINITION
std::ostream& operator<<(std::ostream& out, List& list)			
{

	Iterator it = list.begin();
	out << "(" << *it;
	++it;
	// While the iterator has not reached the end of the list. Used to run through the entire list here.
	while (it != list.end())
	{
		out << "," << *it;
		++it;
	}
	out << ")";

	return out;
}

void fill_list(List& list)
{
	int l_num;
	std::cout << "Please input a set of nonnegative numbers for a List\n(Enter -1 when you are finished):\n" << std::endl;
	// While the user enters readable and appropriate values for data, the loop will run.
	while (std::cin >> l_num)
	{
		// If the value entered from the user is a negative one, break from loop.
		if (l_num == -1)
			break;

		list.push_back(l_num);
	}
	std::cout << "Your list is" << std::endl;
	std::cout << list << "\n" << std::endl;
	
}

void insert_list(List& list)
{
	// This loop always runs unless a break statement has been reached inside the loop. This happens if the user enters -1.
	while (true)
	{
		int temp = 0;
		std::cout << "Select an index for insertion (enter -1 when finished): ";
		std::cin >> temp;
		// While the index entered by the user is larger than the number of nodes in the list object.
		while (temp > list.size())
		{
			std::cout << "ERROR: The index for insertion must be less than or equal to the size of the current list." << std::endl;
			std::cout << "Please try again.\nSelect an index for insertion (enter -1 when finished): ";
			std::cin >> temp;
		}

		// If the index entered by the user is negative one.
		if (temp == -1)
			break;

		Iterator it = list.begin();

		/* For loop to set our iterator location up to the index specified by the user. We use integer for 
		i becasue temp is an integer and we compare with temp.
		*/
		for (int i = 0; i < temp; ++i)			
			++it;

		std::cout << "Select a value for insertion: ";
		std::cin >> temp;

		list.insert(it, temp);
	}
	std::cout << "\n\nThe augmented list is" << std::endl;
	std::cout << list << std::endl;

}

