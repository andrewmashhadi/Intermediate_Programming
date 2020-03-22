#include "All_Cards.h"


Card::Card() :c_inst(" "), p_name(" "), exp_d(" ") { }

Card::Card(const std::string& i, const std::string& n, const std::string& e) : c_inst(i), p_name(n), exp_d(e) { }

std::string Card::get_inst() const
{
	return c_inst;
}

std::string Card::get_name() const
{
	return p_name;
}

std::string Card::get_exp() const
{
	return exp_d;
}

void Card::print() const
{
	std::cout << " ---------------------------------------------" << std::endl;
	std::cout << "|\n";
	std::cout <<"| "<< c_inst << std::endl;
	std::cout << "|      name : " << p_name << std::endl;
	std::cout << "|       exp : "; 

	/* If user entered a 0 as the expiration date, then there is no expiration date for this card. We display
	N/A in this case. Otherwise, we display the expiration date as entered.
	*/
	if (exp_d == "0")
		std::cout << "N/A." << std::endl;
	else
		std::cout << exp_d.substr(0, 2) << '/' << exp_d.substr(2, 2) << '/' << exp_d.substr(4) << std::endl;

	std::cout << "|\n";
}

Card::~Card() { }

IDCard::IDCard() : Card(), ID(" "), DOB(" ") { }

IDCard::IDCard(const std::string& i, const std::string& n, const std::string& e, const std::string& id, const std::string& bd)
	: Card(i, n, e), ID(id), DOB(bd) { }

std::string IDCard::get_ID() const
{
	return ID;
}

std::string IDCard::get_DOB() const
{
	return DOB;
}

void IDCard::print() const
{
	Card::print();
	std::cout << "|       ID# : " << ID << std::endl;
	
	std::cout << "|       DOB : ";

	/* If user entered 0 for date of birth, either it wasn't somehow listed or they did not want to report it.
	So we display N/A in this case. Otherwise we display the date of birth as entered.
	*/
	if (DOB == "0")
		std::cout << "N/A." << std::endl;
	else
		std::cout << DOB.substr(0, 2) << '/' << DOB.substr(2, 2) << '/' << DOB.substr(4) << std::endl;
	std::cout << "|\n";
}

BankCard::BankCard() : Card(), acc_num(" "), sec_num(" ") { }

BankCard::BankCard(const std::string& i, const std::string& n, const std::string& e, const std::string& a, const std::string& s)
	: Card(i,n,e), acc_num(a), sec_num(s) { }

std::string BankCard::get_account() const
{
	return acc_num;
}

std::string BankCard::get_security() const
{
	return sec_num;
}

void BankCard::print() const
{
	Card::print();
	std::cout << "|  Account# : " << acc_num << std::endl;
	std::cout << "|       CSC : " << sec_num << std::endl;
	std::cout << "|\n";
}

// NON-MEMBER FUNCTION DEFINITIONS

std::vector<Card*> fill_cards()
{
	std::vector<Card*> Cards;
	std::cout << "Print Cards by selecting the type (0 when done) : \n" << std::endl;
	std::cout << "1. Basic Card\n2. ID Card\n3. Bank Card" << std::endl;

	// While loop continues to collect new cards and card information untill the loop breaks from the user entering 0
	while (true)
	{
		std::string c_inst, ch_name, exp_d, ID, DOB, a_num, s_num;
		int choice = 0;
		std::cout << "\nCard Type : ";
		std::cin >> choice;
		std::cout << "\n";
		// Continue to re-prompt the user for a new card type if the Card type is not a 0, 1, 2, or 3.
		while (choice < 0 || choice > 3)
		{
			std::cout << "Please enter a value from 0 to 3:\nTry again: ";
			std::cin >> choice;

		}
		// If the card type is entered as 0, the user has no more cards to report, so we break the loop.
		if (choice == 0)
			break;

		std::cout << "Institution name : ";
		std::cin.ignore();
		std::getline(std::cin, c_inst);
		std::cout << "Card holder name : ";
		std::getline(std::cin, ch_name);
		std::cout << "Expiration date mmddyyyy (0 if none) : ";
		std::cin >> exp_d;
		// Check to make sure user entered expiration date in correct format (mmddyyyy), re-prompt if not.
		while (exp_d.length() != 8 && exp_d != "0")
		{
			std::cout << "Entry must be in mmddyyyy format or 0 if no expiration date.\nPlease re-enter Expiration date: ";
			std::cin >> exp_d;
		}

		// If the user enters a 1, we add a basic card with the previously entered information in the vector
		if (choice == 1)
		{
			std::cout << "\n";
			Cards.push_back(new Card(c_inst, ch_name, exp_d));
		}

		/* If the user enters a 2, we add an ID card with the previously entered information plus new information
		about the person's ID number and date or birth. New information is prompted in this if statement.
		*/
		else if (choice == 2)
		{
			std::cout << "ID number : ";
			std::cin >> ID;
			std::cout << "DOB mmddyyyy (0 if not listed) : ";
			std::cin >> DOB;
			//Check to make sure user entered DOB is correct format, re-prompt if not.
			while (DOB.length() != 8 && DOB != "0")
			{
				std::cout << "Entry must be in mmddyyyy format or 0 if not listed.\nPlease re-enter DOB: ";
				std::cin >> DOB;
			}
			std::cout << "\n";
			Cards.push_back(new IDCard(c_inst, ch_name, exp_d, ID, DOB));
		}

		/* If the user enters a 3, we add a bank card with the previously entered information plus new information
		about the person's account number and security code number. New information is prompted in this if statement.
		*/
		else if (choice == 3)
		{
			std::cout << "Account number : ";
			std::cin >> a_num;
			std::cout << "Card Security code : ";
			std::cin >> s_num;
			std::cout << "\n";
			Cards.push_back(new BankCard(c_inst, ch_name, exp_d, a_num, s_num));
		}
	}

	return Cards;
}

void lowest_exp_sort(std::vector<Card*>& Cards)
{
	// Must compare every (kth) element of the Cards vector to the rest of the vector behind the (kth) element.
	for (size_t k = 0; k < Cards.size(); k++)
	{
		std::string earliest_d = Cards[k]->get_exp();
		size_t earliest_ind = k;

		/* This is the for loop comparing every element behind the kth element to find the earliest card expiration date
		from the kth element to the end of the vector.
		*/
		for (size_t i = k; i < Cards.size(); i++)
		{
			/* If the ith card expiration is N/A, we swap it with the kth element, so all the N/A expiration dates are
			at the front of the Cards vector.
			*/
			if (Cards[i]->get_exp() == "0")
			{
				earliest_ind = i;
				break;
			}

			/* If the year of the (earliest_ind)th Card element expiration date is less than the ith Card element expiration date, 
			(earliest_ind)th is still our earliest so far in this for loop, so we don't even compare any further and we move onto
			compare the (i+1)th element.
			*/
			if (earliest_d.substr(4) < (Cards[i]->get_exp()).substr(4))
			{
				continue;
			}

			/* If the year of the (earliest_ind)th Card expiration date is later than the ith Card expiration date,
			then we make our earliest_ind this ith element, since it expires earlier.
			*/
			else if (earliest_d.substr(4) > (Cards[i]->get_exp()).substr(4))
			{
				earliest_d = Cards[i]->get_exp();
				earliest_ind = i;
			}

			/* If the year of the (earliest_ind)th Card element expiration date is the same as the ith Card element expiration date, 
			but the month is earlier, the (earliest_ind)th is still our earliest so far in this for loop, so we don't even compare any 
			further and we move onto compare the (i+1)th element.
			 */
			else if ((earliest_d.substr(0, 2) < (Cards[i]->get_exp()).substr(0, 2)))
			{
				continue;
			}

			/* If the year of the (earliest_ind)th Card expiration date is the same as the ith Card expiration date,
			but the month is later, then we make our earliest_ind this ith element, since it expires earlier.
			*/
			else if ((earliest_d.substr(0, 2) > (Cards[i]->get_exp()).substr(0, 2)))
			{
				earliest_d = Cards[i]->get_exp();
				earliest_ind = i;
			}

			/* If the month and year of the (earliest_ind)th Card element expiration date is the same as the ith Card element 
			expiration date, but the day is earlier, the (earliest_ind)th is still our earliest so far in this for loop, 
			so we don't even compare any further and we move onto compare the (i+1)th element.
			 */
			else if ((earliest_d.substr(2, 2) < (Cards[i]->get_exp()).substr(2, 2)))
			{
				continue;
			}

			/* If the month and year of the (earliest_ind)th Card expiration date is the same as the ith 
			Card expiration date, but the day is later, then we make our earliest_ind this ith element, since 
			it expires earlier.
			*/
			else if ((earliest_d.substr(2, 2) > (Cards[i]->get_exp()).substr(2, 2)))
			{
				earliest_d = Cards[i]->get_exp();
				earliest_ind = i;
			}
		}

		Card* temp_ptr = Cards[k];
		Cards[k] = Cards[earliest_ind];
		Cards[earliest_ind] = temp_ptr;
	}
}

void display_cards(const std::vector<Card*>& Cards)
{

	size_t zeros_count = 0;

	/* Skips all the cards without expiration dates, then displays the details of each element of the sorted 
	Cards vector (using polymorphisms for ID or bank cards) by calling the print member function. 
	*/
	for (size_t i = 0; i < Cards.size(); i++)
	{
		if (Cards[i]->get_exp() == "0")
		{
			zeros_count++;
			continue;
		}

		Cards[i]->print();
	}

	// Prints all the beginning Cards vector elements that do not have expiration dates.
	for (size_t j = 0; j < zeros_count; j++)
	{
		Cards[j]->print();
	}

}
