#include "LinkedList.h"


int main()
{
	List int_list;
	fill_list(int_list);
	insert_list(int_list);

	std::cout << "\nWhen we sort the previous list we obtain" << std::endl;
	int_list.sort();
	std::cout << int_list << std::endl;
	std::cout << "And this sorted list in reverse order is" << std::endl;
	int_list.reverse();
	std::cout << int_list << std::endl;
	std::cout << "If we merge this list with the list (2,3,5,7,11) we obtain" << std::endl;
	List other_list;
	other_list.push_back(2);
	other_list.push_back(3);		
	other_list.push_back(5);
	other_list.push_back(7);
	other_list.push_back(11);
	List merged_list = int_list.merge(other_list);
	std::cout << merged_list << std::endl;
	

	return 0;
}
