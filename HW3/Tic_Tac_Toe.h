/*
Andrew Mashhadi
ID: 905092387
PIC 10B
Programming Homework #1

Honesty Pledge:

I, Andrew Mashhadi, pledge that this is my own individual work,
which conforms to the guidelines of academic honesty as described
in the course syllabus.
*/

#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

const size_t BRD_SIZE = 3;

class Person
{
private:
	std::string name;
	int score;

public:
	Person();
	Person(const std::string &);
	std::string getName() const;
	int getScore() const;
	void IncScore();
};

class Game
{
private:
	Person* p_1;
	Person* p_2;
	std::vector<std::vector<std::string>> grid;
	size_t n_games;
	bool has_won(const std::string &) const;
	bool full();
	void clear_grid();
	void provide_space() const;
	void mark_location(Person*,const std::string &, bool &);

public:
	Game();
	Game(Person*, Person*, size_t);
	void print_grid() const;
	void play_games();
};

#endif
