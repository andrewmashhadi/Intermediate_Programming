/*
Andrew Mashhadi
ID: 905092387
PIC 10B
Programming Homework #3

Honesty Pledge:

I, Andrew Mashhadi, pledge that this is my own individual work,
which conforms to the guidelines of academic honesty as described
in the course syllabus.
*/


#ifndef FILE_PROP
#define FILE_PROP

#include <iostream>
#include <string>
#include <fstream>

class iFile_W_Props
{

private: 

	std::ifstream file;
	std::string f_name;

	/* Reads through every possible line and uses a loop to find the total number of lines in this class's
	file member field.
	@return the total count of lines
	*/
	size_t num_lines();

public:

	/* Constructs our iFile_W_Props class, assigning our class's file name to n and opening our input file with 
	our new file name. Also makes sure the file is opened properly using a loop with the fail() flag.  
	@param n is the string that our class's input file name is set to
	*/
	iFile_W_Props(const std::string& n); 

	/* Gets this class's input file name.
	@return the file name*/
	std::string get_name() const;

	/* Uses random access ifstream member functions to get the total number of charactors in this class's file member field.
	@return the number of charactors before the end of file, which is a long long on my system (using .tellg())
	*/
	long long num_chars();

	/* Reads every word and uses a loop to find the total number of words in this class's file member field.
	@return the total count of words */
	size_t num_words();

	/* Since the directions do not specify exactly which objects we have to overload the comparison operator for to
	compare the number of lines in each input file, we compare our iFile_W_Props objects containing there own files
	instead of overloading the comparison operators with a non-member function containing two ifstream objects.
	Approved by Professor. */

	/* Overloaded operator compares this iFile_W_Props object with another iFile_W_Props object by using the
	number of lines of data in each object's input file member. 
	@param the iFile_W_Props obj that we compare this object to, using the number of lines in each object's file member field
	@return true if this iFile_W_Props has an input file member containing less lines of data than the input 
	file member that is in the passed in iFile_W_Props object (obj), returns false otherwise 
	*/
	bool operator<(iFile_W_Props& obj);

	/* Overloaded operator compares this iFile_W_Props object with another iFile_W_Props object by using the
	number of lines of data in each object's input file member.
	@param the iFile_W_Props obj that we compare this object to, using the number of lines in each object's file member field
	@return true if this iFile_W_Props has an input file member containing more lines of data than the input
	file member that is in the passed in iFile_W_Props object (obj), returns false otherwise
	*/
	bool operator>(iFile_W_Props& obj);

	/* Overloaded operator compares this iFile_W_Props object with another iFile_W_Props object by using the
	number of lines of data in each object's input file member.
	@param the iFile_W_Props obj that we compare this object to, using the number of lines in each object's file member field
	@return true if this iFile_W_Props has an input file member containing the same amount of lines as the 
	file member that is in the passed in iFile_W_Props object (obj), returns false otherwise
	*/
	bool operator==(iFile_W_Props& obj);

	/* Right before this iFile_W_Props object is destroyed (or the program ends), it uses this destructor to 
	automatically close our object's previously opened input file member. 
	*/
	~iFile_W_Props();

};

//NON-MEMBER FUNCTION DECLARATION

/* This non-member function is meant to print all of the public properties of the file member found in a
iFile_W_Props object. It displays the name of the file, number of characters in the file, and the number of words
in the file.
@param out is a reference to an ostream to allow for a more generalized function, now we can pass in an
ostream or ofstream object to display properties to the console or an output file, respectfully (inhertited)
@param in is a reference to the iFile_W_Props object containing the input file member field and the member functions we
want to use to display that files properties
@return void
*/
void print_props(std::ostream& out, iFile_W_Props& in);

#endif