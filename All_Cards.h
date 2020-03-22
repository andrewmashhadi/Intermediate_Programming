/*
Andrew Mashhadi
ID: 905092387
PIC 10B
Programming Homework #4

Honesty Pledge:

I, Andrew Mashhadi, pledge that this is my own individual work,
which conforms to the guidelines of academic honesty as described
in the course syllabus.
*/


#ifndef ALL_CARDS_H
#define ALL_CARDS_H
#include <iostream>
#include <vector>
#include <string>

class Card
{

private: 
	std::string c_inst;
	std::string p_name;
	std::string exp_d;

public:
	// Defult constructor used to construct a basic Card object with each member field assigned to an empty string.
	Card();

	/* Constructor with parameters used to construct a basic Card object with the institution name set to i,
	the person's name set to n, and the expiration date set to e.
	@param i is const reference to a string that our ID will be set to 
	@param n is a constant reference to a string that our person's name will be set to
	@param e is a constant reference to a string that our expiration date will be set to
	*/
	Card(const std::string& i,const std::string& n, const std::string& e);

	/* Accessor member function, returning this object's institution name. Impotant for use in derived class.
	@return the string member variable that holds the institution's name, c_inst.
	*/
	std::string get_inst() const;

	/* Accessor member function, returning this object's person's name. Impotant for use in derived class.
	@return the string member variable that holds the person's name, p_name. 
	*/
	std::string get_name() const;

	/* Accessor member function, returning this object's expiration date. Impotant for use in derived class.
	@return the string member variable that holds the expiration date, exp_d.
	*/
	std::string get_exp() const;

	/* This is a virtual member function that displays our member field's information as the format is shown in
	the directions. It prints the institution name, the person's name, and the expiration date.
	@return void
	*/
	virtual void print() const;

	// Have to define a virtual destructor when using a polymorphism.
	virtual ~Card();

};

class IDCard : public Card
{
private:
	std::string ID;
	std::string DOB;
	

public:
	/* Defult constructor used to construct an IDCard object with each member field in this derived class 
	assigned to an empty string. Also calls the default constructor for the base class so that the base class
	member feilds are set to empty strings as well.
	*/
	IDCard();

	/* Constructor with parameters used to construct an IDCard object and assign our derived class member variables
	to the members passed in and to also call our base class's constructor with parameters so its member variables 
	can also be assigned to the corresponding parameters passed in. 
	@param i is const reference to a string that our ID will be set to (argument for base class constructor call)
	@param n is a constant reference to a string that our person's name will be set to (argument for base class constructor call)
	@param e is a constant reference to a string that our expiration date will be set to (argument for base class constructor call)
	@param id is a constant reference to a string that our id number will be set to
	@param bd is a constant reference to a string that our date of birth will be set to
	*/
	IDCard(const std::string& i, const std::string& n, const std::string& e, const std::string& id, const std::string& bd);


	/* Accessor member function, returning this object's ID number member variable, ID.
	@return the string member variable that holds the ID number, ID.
	*/
	std::string get_ID() const;

	/* Accessor member function, returning this object's date of birth member variable, DOB .
	@return the string member variable that holds the date of birth, DOB.
	*/
	std::string get_DOB() const;

	/* This is a virtual member function that displays all of our member field info as the format is shown in
	the directions (virtual not required here). It calls the base class print function and also displays this objects
	additional information about the card holder's ID number and date of birth (ID and DOB member variables).
	@return void
	*/
	virtual void print() const;

};

class BankCard : public Card
{

private:
	std::string acc_num;
	std::string sec_num;

public:
	/* Defult constructor used to construct a BankCard object with each member field in this derived class
	assigned to an empty string. Also calls the default constructor for the base class so that the base class
	member feilds are set to empty strings as well.
	*/
	BankCard();

	/* Constructor with parameters used to construct a BankCard object and assign our derived class member variables
	to the members passed in and to also call our base class's constructor with parameters so its member variables
	can also be assigned to the corresponding parameters passed in.
	@param i is const reference to a string that our ID will be set to (argument for base class constructor call)
	@param n is a constant reference to a string that our person's name will be set to (argument for base class constructor call)
	@param e is a constant reference to a string that our expiration date will be set to (argument for base class constructor call)
	@param a is a constant reference to a string that our account number will be set to
	@param s is a constant reference to a string that our security code number will be set to
	*/
	BankCard(const std::string& i, const std::string& n, const std::string& e, const std::string& a, const std::string& s);

	/* Accessor member function, returning this object's account number member variable, acc_num.
	@return the string member variable that holds the account number, acc_num.
	*/
	std::string get_account() const;

	/* Accessor member function, returning this object's security code number, sec_num.
	@return the string member variable that holds the security code number, sec_num.
	*/
	std::string get_security() const;

	/* This is a virtual member function that displays our all of our member field info as the format is shown in
	the directions (virtual not required here). It calls the base class print function and also displays this objects
	additional information about the card holder's account number and security code number, (acc_num and sec_num).
	@return void
	*/
	virtual void print() const;

};

// NON-MEMBER FUNCTIONS DECLARATIONS

/* This non-member function asks the user for all the cards (basic, ID, or BankCard) and their associated inforation 
until the user presses 0 when choosing a card type (breaks the while loop). Using if statements, when the user enters 
a basic card it only asks for the basic information, when the user enters an ID card it also asks for ID number and
birth date, and when the user enters a Bank Card it additionally asks for account and security code numbers.
@return a vector of pointers to Cards. Each element should be a pointer to a dynamically allocated Basic, ID, 
or Bank card object with the corresponding information from the user. (Ellements are allowed to point to ID and Bank 
cards since they are derived classes.)
*/
std::vector<Card*> fill_cards();

/* This non-member function sorts the vector of pointers to Card objects from the earliest expiration date to the 
latest. It puts all of the Cards without a proper expiration date at the front of the vector. 
@param a reference to the vector will will be sorting in the function. Must be a reference since we want to change the
structure of the passed in vector
@return void
*/
void lowest_exp_sort(std::vector<Card*>& Cards);

/* This non-member function skips all of the Cards with no expiration date in our vector and then displays the rest
of the element that our sorted vector points to. It displays in order from earliest expiring cards to latest 
expiring cards. It also uses another for loop to display the contents of the Cards without an expiration date.
When the print function is applied to an element that is a derived card class, a polymorphism is being used.
@param constant reference to the vector of Card pointers that contains the addresses of the Cards we plan to print
@return void
*/
void display_cards(const std::vector<Card*>& Cards);

#endif