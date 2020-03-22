#include "All_Cards.h"


int main()
{
	std::cout << "*********************" << std::endl;
	std::cout << "*  Wallet Printer!  *" << std::endl;
	std::cout << "*********************\n" << std::endl;

	std::vector<Card*> Cards = fill_cards();
	lowest_exp_sort(Cards);
	display_cards(Cards);

	for (size_t i = 0; i < Cards.size(); i++)
	{
		delete Cards[i];
	}

	return 0;
}

