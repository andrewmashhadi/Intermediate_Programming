#include "Students_and_Clubs.h"

// Default constructor for a Student object. Sets the students name to a white space string.
Student::Student() :student_name(" ") {}

/* Overloaded constructor that takes string parameter. Sets the student name to the parameter passed in.
@param name is the string that our Student's name is set to
*/
Student::Student(const std::string& name) :student_name(name) {}

/* Accessor member function for the Student object's name.
@return the name of this student
*/
std::string Student::get_name() const
{
	return student_name;
}

/* Only constructor for StudentClub object. Sets this club's pointers to president, vice-president, secretary,
and treasurer student objects.
@param p is a pointer to a student, this address is what our president pointer will point to
@param v is a pointer to a student, this address is what our vice_president pointer will point to
@param s is a pointer to a student, this address is what our secretary pointer will point to
@param t is a pointer to a student, this address is what our treasurer pointer will point to
@param m is a const reference to a vector containing pointers to student objects. Contains only unique 
club officer Student objects. No elements of the vector have the name. 
*/
StudentClub::StudentClub(Student* p, Student* v, Student* s, Student* t, const std::vector<Student*>& m)
	:President(p), Vice_President(v), Secretary(s), Treasurer(t), club_members(m) {}

/* Accessor member function for the StudentClub's President.
@return the pointer to the president's student object location.
*/
Student* StudentClub::get_president() const
{
	return President;
}

/* Accessor member function for the StudentClub's Vice-president.
@return the pointer to the vice-president's student object location.
*/
Student* StudentClub::get_vice_president() const
{
	return Vice_President;
}

/* Accessor member function for the StudentClub's secretary.
@return the pointer to the secretary's student object location.
*/
Student* StudentClub::get_secretary() const
{
	return Secretary;
}

/* Accessor member function for the StudentClub's treasurer.
@return the pointer to the treasurer's student object location.
*/
Student* StudentClub::get_treasurer() const
{
	return Treasurer;
}

/* Accessor member function for the StudentClub's unique club members vector.
@return the vector of pointers to unique student objects.
*/
std::vector<Student*> StudentClub::get_members() const
{
	return club_members;
}

/* Student club member function that adds a member to the vector student pointers containing unique 
members in each element. Does not check for student object uniqueness before adding the address of a new
student, so we must check that the name of the new student object is not the same as any other members 
before calling this member function, or else not all the elements will be unique.
@param s is the pointer to the new student object that will be added to the club members vector
@return void
*/
void StudentClub::add_member(Student* s)
{
	club_members.push_back(s);
}

/* Student club member function is used for the user to enter any new member names. This checks to make sure
the new member has not already been recorded as a member before. If none of the club member pointers point to
a student object with the same name as the name entered, we dynamically add a new student object pointer
to the unique club members vector by calling this object's add_member.
@return void
*/
void StudentClub::new_club_members()
{
	/* This while loop will run until the break is reached. The break will be reached only when the if
	statement is executed. The if statement will execute only if the user enters a single q or Q (for quit).
	*/
	while (true)
	{
		std::string new_name;
		std::cout << "\nNew Member (Q to quit): ";
		std::getline(std::cin, new_name);

		// If the new name is entered as an uppercase or lowercase q (for quit), we break from the while loop.
		if (new_name == "Q" || new_name == "q")
			break;

		bool existing_member = false;

		/* This for loop iterates through every (unique) student pointer in this object's club_members
		vector. Used to make sure the new name is not the same name as any of the original students in
		our club.
		*/
		for (size_t i = 0; i < club_members.size(); i++)
		{
			/* If the ith club member has the same name as the entered name, set the existing member to true,
			so it doesn't add a new Student pointer to our club members.
			*/
			if (club_members[i]->get_name() == new_name)
			{
				std::cout << "This member has already been recorded. Please only enter new members." << std::endl;
				existing_member = true;
				break;
			}
		}
		/* If none of the names of the club_members in this student club are the same as the entered name,
		then we add a new student with the entered name to this student club.
		*/
		if (!existing_member)
			add_member(new Student(new_name));
	}
}

/* Student club member function that returns the number of uniquely named Students in the club. This is
easy since the club_members vector of student pointers is holding pointers to all the uniquely named
Students in the club.
@return the number of uniquely named students in the club*/
size_t StudentClub::number_members() const
{
	return club_members.size();
}

/* Student Club member function that prints this club's officer names (president, vice-president, secretary,
and treasurer).
@return void
*/
void StudentClub::print_officers() const
{
	std::cout << std::setw(17) << "President: " << President->get_name() << std::endl;
	std::cout << std::setw(17) << "Vice President: " << Vice_President->get_name() << std::endl;
	std::cout << std::setw(17) << "Secretary: " << Secretary->get_name() << std::endl;
	std::cout << std::setw(17) << "Treasurer: " << Treasurer->get_name() << std::endl;
}

/* Destructor for StudentClub class. Since the club members vector contains pointers to all the unique student 
ojects that were all added using the "new" operator, they are all located in the heap. All of these addresses
must be freed back up after the StudentClub object is destroyed.
*/
StudentClub::~StudentClub()
{
	for (size_t n = 0; n < club_members.size(); n++)
		delete club_members[n];
}

// NON-MEMBER FUNCTION DEFINITION

/* Non-member function, meant to be called in the main. Prompts the user to enter the names of all 
officers. This function's parameter is a pointer, meant to be pointed to an array of strings that are meant
to hold the officer names (0th element is president), 1st element is vice-president, 2nd element is 
secretary, 3rd element is treasurer). Since it is a pointer, the values in the array passed in will be altered.
@param names is a string pointer, meant to be pointing to the first element of an array of strings for the 
officer names
*/
void get_officer_names(std::string* names)
{
	std::cout << "President: ";
	std::getline(std::cin, names[0]);
	std::cout << "\nVice-President: ";
	std::getline(std::cin, names[1]);
	std::cout << "\nSecretary: ";
	std::getline(std::cin, names[2]);
	std::cout << "\nTreasurer: ";
	std::getline(std::cin, names[3]);
}
