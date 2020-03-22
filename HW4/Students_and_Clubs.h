/*
Andrew Mashhadi
ID: 905092387
PIC 10B
Programming Homework #2

Honesty Pledge:

I, Andrew Mashhadi, pledge that this is my own individual work,
which conforms to the guidelines of academic honesty as described
in the course syllabus.
*/

#ifndef STUDENTS_AND_CLUBS_H
#define STUDENTS_AND_CLUBS_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

const size_t OFFICER_ROLES = 4;

class Student
{

private:
	std::string student_name;

public:
	Student();
	Student(const std::string&);
	std::string get_name() const;

};


class StudentClub
{

private:
	Student* President;
	Student* Vice_President;
	Student* Secretary;
	Student* Treasurer;
	std::vector<Student*> club_members;

public:
	StudentClub(Student*, Student*, Student*, Student*, const std::vector<Student*>&);
	Student* get_president() const;
	Student* get_vice_president() const;
	Student* get_secretary() const;
	Student* get_treasurer() const;
	std::vector<Student*> get_members() const;
	void add_member(Student* s);
	void new_club_members();
	size_t number_members() const;
	void print_officers() const;
	~StudentClub();
	
};

// NON-MEMBER FUNCTION DECLARATION

void get_officer_names(std::string*);


#endif
